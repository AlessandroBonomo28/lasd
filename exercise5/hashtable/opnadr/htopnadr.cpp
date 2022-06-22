
namespace lasd {

/* ************************************************************************** */

// ...


template<typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr() noexcept{
    vector = Vector<Data>(buckDim);
    flags = Vector<char>(buckDim);
    for(ulong i = 0; i < buckDim; ++i){
        flags[i] = 'E';
    }
}

// Specific constructors
template<typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong size) noexcept{
    buckDim = size;
    vector = Vector<Data>(buckDim);
    flags = Vector<char>(buckDim);
    for(ulong i = 0; i < buckDim; ++i){
        flags[i] = 'E';
    }
}

template<typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const LinearContainer<Data>& lc) noexcept{
    buckDim = lc.Size();
    vector = Vector<Data>(buckDim);
    flags = Vector<char>(buckDim);
    for(ulong i = 0; i < buckDim; ++i){
        flags[i] = 'E';
    }
    for (ulong i = 0; i < lc.Size(); i++) 
        Insert(lc[i]);
    
}

template<typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr( const ulong size,const LinearContainer<Data>& lc)noexcept {
    buckDim = size;
    vector = Vector<Data>(buckDim);
    flags = Vector<char>(buckDim);
    for(ulong i = 0; i < buckDim; ++i){
        flags[i] = 'E';
    }
    for (ulong i = 0; i < lc.Size(); i++) 
        Insert(lc[i]);
}

// Copy constructor
template<typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr& copyTable)noexcept {
    
    
    if(copyTable.dim!=0){
        dim = copyTable.dim;
        buckDim = copyTable.buckDim;
        cancellati = copyTable.cancellati;
        vector = Vector<Data>(copyTable.vector.Size());
        flags = Vector<char>(copyTable.flags.Size());
        x = copyTable.x;
        y = copyTable.y;
         for (ulong i = 0; i < copyTable.vector.Size(); ++i){
        vector[i] = copyTable.vector[i];
        }
        for(ulong i = 0; i < copyTable.flags.Size(); ++i){
            flags[i] = copyTable.flags[i];
        }
    }else{
        Clear();
    }
}

// Move constructor
template<typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr&& table) noexcept {
    std::swap(vector, table.vector);
    std::swap(flags, table.flags);
    std::swap(dim, table.dim);
    std::swap(buckDim, table.buckDim);
    std::swap(x, table.x);
    std::swap(y, table.y);
    std::swap(cancellati, table.cancellati);
}



template <typename Data>
HashTableOpnAdr<Data> & HashTableOpnAdr<Data>::operator=(const HashTableOpnAdr<Data> & copyTable) noexcept{
    HashTableOpnAdr<Data>* tmp = new HashTableOpnAdr(copyTable);
    std::swap(*this,*tmp);
    delete tmp;
    return *this;
}

// Move assignment
template<typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(HashTableOpnAdr&& table) noexcept {
    std::swap(vector,table.vector);
    std::swap(flags,table.flags);
    std::swap(dim,table.dim);
    std::swap(buckDim,table.buckDim);
    std::swap(x,table.x);
    std::swap(y,table.y);
    std::swap(cancellati,table.cancellati);
    return *this;
}

// Comparison operators
template<typename Data>
bool HashTableOpnAdr<Data>::operator==(const HashTableOpnAdr& table) const noexcept {
    if (dim != table.dim)
        return false;
    else {
        
        for(ulong i = 0; i < buckDim; i++){
            if(flags[i] == 'F')            
                if(!(table.Exists(vector[i]))){
                    return false;
                }
                
            }
        }
        return true;
}
 

template<typename Data>
bool HashTableOpnAdr<Data>::operator!=(const HashTableOpnAdr& table) const noexcept {
    return !(*this == table);
}



template<typename Data>
void HashTableOpnAdr<Data>::Map(MapFunctor function, void* ptr){
    for(ulong i = 0; i < buckDim; i++){
        if(flags[i] == 'F'){
            function(vector[i],ptr);
        }
    }
}

template<typename Data>
void HashTableOpnAdr<Data>::Fold(FoldFunctor function, const void* ptr, void* acc) const{
    for(ulong i = 0; i < buckDim; i++){
        if(flags[i] == 'F'){
            function(vector[i], ptr, acc);
        }
    }
}

template<typename Data>
void HashTableOpnAdr<Data>::Clear() noexcept {
    for(ulong i = 0; i < buckDim; ++i){
        flags[i] = 'E';
    }
    dim = 0;
}

template <typename Data>
void HashTableOpnAdr<Data>::Resize(ulong newSize) noexcept{
    HashTableOpnAdr<Data> newTable(newSize);
    for (ulong i = 0; i < buckDim; i++) {
                if(flags[i] == 'F'){
                    newTable.Insert(vector[i]);
                }
            }
    std::swap(*this, newTable);
}
template<typename Data>
void HashTableOpnAdr<Data>::Print()const noexcept{
    for (ulong i = 0; i < buckDim; i++) {
        std::cout<<vector[i]<<" ";
    }
    std::cout<<" [Size:"<<dim<<"]"<<std::endl;
}
// Specific member functions (inherited from DictionaryContainer)


template<typename Data>
bool HashTableOpnAdr<Data>::Insert(const Data& data) noexcept {
    if(dim >= buckDim/2)
        Resize(buckDim*2);

    ulong tmp = HashTable<Data>::HashKey(data);
    if (!Exists(data)) {
        ulong tmp = HashTable<Data>::HashKey(data);
        if (flags.operator[](tmp) == 'E' || flags.operator[](tmp) == 'R') { // if the bucket is empty
            vector.operator[](tmp) = data;
            flags.operator[](tmp) = 'F';
            dim++;
            return true;
        }
        else if (flags.operator[](tmp) == 'F') { // collision
            ulong tmp2 = FindEmpty(tmp);
            vector.operator[](tmp2) = data;
            flags.operator[](tmp2) = 'F';
            dim++;
            return true;
        }
    }
    return false;
}

template<typename Data>
bool HashTableOpnAdr<Data>::Insert(Data&& data) noexcept {
    if(dim >= buckDim/2)
        Resize(buckDim*2);
    if (!Exists(data)) {
        ulong tmp = HashTable<Data>::HashKey(data);
        if (flags.operator[](tmp) == 'E' || flags.operator[](tmp) == 'R') { // if the bucket is empty
            std::swap(vector.operator[](tmp), data);
            flags.operator[](tmp) = 'F';
            dim++;
            return true;
        }
        else if (flags.operator[](tmp) == 'F') { // collision
            ulong tmp2 = FindEmpty(tmp);
            std::swap(vector.operator[](tmp2), data);
            flags.operator[](tmp2) = 'F';
            dim++;
            return true;
        }
    }
    return false;
}

template<typename Data>
bool  HashTableOpnAdr<Data>::Exists(const Data& data) const noexcept {
    ulong tmp = HashTable<Data>::HashKey(data);
    if(flags[tmp] == 'F' && vector[tmp] == data){
        return true;
    }
    ulong offset = tmp+1;
    for( ulong i = offset; i < buckDim + offset; i++){
        if(flags[i % buckDim] == 'F' && vector[i % buckDim] == data){
            return true;
        }
    }
    return false;
}


template <typename Data>
bool HashTableOpnAdr<Data>::Remove(const Data& data) noexcept{
    if(Exists(data)){
        ulong tmp = Find(data);
        flags[tmp] = 'R';
        dim--;
        cancellati++;
        if(cancellati>= buckDim/2){
            Resize(buckDim/2);
            cancellati = 0;
        }
        return true;
    }
    
    return false;
    
}




template<typename Data>
ulong HashTableOpnAdr<Data>::HashKey(const ulong& assr, const ulong& index ) const{
    return (assr + index) % buckDim;
}


template<typename Data>
ulong  HashTableOpnAdr<Data>::Find(const Data& data) const noexcept{
   ulong start = HashTable<Data>::HashKey(data);
   for(ulong i = start; i < buckDim+start; i++){
        if(flags[i%buckDim] == 'F' && vector[i%buckDim] == data){
            return i%buckDim;
        }
    }
    return 0;
}

template<typename Data>
ulong  HashTableOpnAdr<Data>::FindEmpty(ulong& collisionIndex) const noexcept{
    ulong offset =collisionIndex+1;
    for(int i=offset; i < buckDim+offset; i++){
        if(flags[i%buckDim] == 'E' || flags[i%buckDim] == 'R'){
            return i%buckDim;
    }
    
    }
    return collisionIndex;
}
/* ************************************************************************** */

}
