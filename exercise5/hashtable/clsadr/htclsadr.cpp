
namespace lasd {

/* ************************************************************************** */

template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr() noexcept{
    buckets = Vector<BST<Data>>(buckDim);
}

// Specific constructors
template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const ulong size) noexcept{
    buckDim = size;
    buckets = Vector<BST<Data>>(buckDim);
}

template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const LinearContainer<Data>& lc) noexcept{
    buckDim = lc.Size();
    buckets = Vector<BST<Data>>(buckDim);
    for (ulong i = 0; i < lc.Size(); i++) 
        Insert(lc[i]);
    
}

template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr( const ulong size,const LinearContainer<Data>& lc)noexcept {
    buckDim = size;
    buckets = Vector<BST<Data>>(buckDim);
    for (ulong i = 0; i < lc.Size(); i++) 
        Insert(lc[i]);
}

// Copy constructor
template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr& table)noexcept {
    
    if(table.dim!=0){
        buckDim = table.buckDim;
        buckets = Vector<BST<Data>>(table.buckDim);
        x = table.x;
        y = table.y;
         for (ulong i = 0; i < table.buckDim; i++) {
            if(table.buckets[i].Size()!=0){
                BTInOrderIterator<Data> it(table.buckets[i]);
                while (!it.Terminated()) {
                    Insert(it.operator*());
                    it.operator++();
                }    
            }
            
        }
    }else{
        Clear();
    }
}

// Move constructor
template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr&& table) noexcept {
    std::swap(buckets, table.buckets);
    std::swap(dim, table.dim);
    std::swap(buckDim, table.buckDim);
    std::swap(x, table.x);
    std::swap(y, table.y);
}



template <typename Data>
HashTableClsAdr<Data> & HashTableClsAdr<Data>::operator=(const HashTableClsAdr<Data> & copyTable) noexcept{
    HashTableClsAdr<Data>* tmp = new HashTableClsAdr(copyTable);
    std::swap(*this,*tmp);
    delete tmp;
    return *this;
}

// Move assignment
template<typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(HashTableClsAdr&& table) noexcept {
    std::swap(buckets,table.buckets);
    std::swap(dim,table.dim);
    std::swap(buckDim,table.buckDim);
    std::swap(x,table.x);
    std::swap(y,table.y);
    return *this;
}

// Comparison operators
template<typename Data>
bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr& table) const noexcept {
    if (dim != table.dim)
        return false;
    else {
        for (ulong i = 0; i < buckDim; i++) {
            if(buckets[i].Size()!=0){
                BTInOrderIterator<Data> it(buckets[i]);
                while (!it.Terminated()) {
                    if (!table.Exists(it.operator*()))
                     return false;
                    
                    it.operator++();
                }    
            }
            
        }
        return true;
    }
} 

template<typename Data>
bool HashTableClsAdr<Data>::operator!=(const HashTableClsAdr& table) const noexcept {
    return !(*this == table);
}


template<typename Data>
void HashTableClsAdr<Data>::Resize(const ulong newSize) noexcept{
    HashTableClsAdr<Data> tmp(newSize);
    for(ulong i=0;i<buckDim;i++){
        if(buckets[i].Size()!=0){
            BTInOrderIterator<Data> it(buckets[i]);
            while(!it.Terminated()){
                tmp.Insert(it.operator*());
                it.operator++();
            }
        }
    }
    std::swap(*this,tmp);
}
template<typename Data>
void HashTableClsAdr<Data>::Print()const noexcept{
    for (ulong i = 0; i < buckDim; i++) {
        if(buckets[i].Size()!=0){
            BTInOrderIterator<Data> it(buckets[i]);
            while (!it.Terminated()) {
                std::cout<<it.operator*()<<" ";
                it.operator++();
            }
        }
        
    }
    std::cout<<" [Size:"<<dim<<"]"<<std::endl;
}
// Specific member functions (inherited from DictionaryContainer)

template<typename Data>
bool HashTableClsAdr<Data>::Insert(const Data& data) noexcept {
    ulong i = HashTable<Data>::HashKey(data);
    bool esito = buckets[i].Insert(data);
    if (esito) {
        dim++;
        return true;
    }
    else
        return false;
}

template<typename Data>
bool HashTableClsAdr<Data>::Insert(Data&& data) noexcept {
    ulong i = HashTable<Data>::HashKey(data);
    bool esito = buckets[i].Insert(std::move(data));
    if (esito) {
        dim++;
        return true;
    }
    else
        return false;
}

template<typename Data>
bool HashTableClsAdr<Data>::Remove(const Data& data) noexcept{
    ulong i = HashTable<Data>::HashKey(data);
    bool esitoRemove = buckets[i].Remove(data);
    if (esitoRemove) {
        dim--;
        
        return true;
    }
    else
        return false;
}

// Specific memeber functions (inherited from TestableContainer)

template<typename Data>
bool HashTableClsAdr<Data>::Exists(const Data& data) const noexcept {
    for (ulong i = 0; i < buckDim; i++) {
        if(buckets[i].Size()!=0){
            BTInOrderIterator<Data> it(buckets[i]);
            while (!it.Terminated()) {
                if (it.operator*() == data)
                    return true;
                else
                    it.operator++();
            }
        }
       
    }
    return false;
} 


// Specific member functions (inherited from MappableContainer)

template<typename Data>
void HashTableClsAdr<Data>::Map(MapFunctor fun, void* opt) {
    for (ulong i = 0; i < buckDim; i++)
        buckets[i].Map(fun, opt);
}

// Specific member functions (inherited from FoldableContainer)

template<typename Data>
void HashTableClsAdr<Data>::Fold(FoldFunctor fun, const void* par, void* acc) const {
    for (ulong i = 0; i < buckDim; i++)
        buckets[i].Fold(fun, par, acc);
}

// Specific member functions (inherited from Container)

template<typename Data>
void HashTableClsAdr<Data>::Clear() noexcept{
    for (ulong i = 0; i < buckDim; i++)
    {
        if(buckets[i].Size()!=0){
            buckets[i].Clear();
        }
    }
    dim = 0;
    
}
/* ************************************************************************** */

}
