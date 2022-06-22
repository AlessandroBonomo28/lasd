
namespace lasd {

/* ************************************************************************** */

template<typename Data>
QueueVec<Data>::QueueVec(const LinearContainer<Data> & copyContainer){
    dim = copyContainer.Size();
    
    DataVector = new Data[dim];
    dimLogQueue = dim;
    for(ulong i =0;i<copyContainer.Size();i++){
        DataVector[i] = copyContainer[i];
    }
}

template<typename Data>
QueueVec<Data>::QueueVec(const QueueVec<Data>& copyQueue) noexcept{
    head = copyQueue.head;
    dim = copyQueue.Size();
    DataVector = new Data[dim];
    dimLogQueue = copyQueue.dimLogQueue;
    for(ulong i =0;i<copyQueue.Size();i++){
        DataVector[i] = copyQueue[i];
    }
    
}
template<typename Data>
QueueVec<Data>::QueueVec(QueueVec<Data>&& copyQueue) noexcept{
    std::swap(dim,copyQueue.dim);
    std::swap(head,copyQueue.head);
    std::swap(DataVector,copyQueue.DataVector);
    std::swap(dimLogQueue,copyQueue.dimLogQueue);
}

template<typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec& copyQueue) noexcept{
    Clear();
    head = copyQueue.head;
    dim = copyQueue.Size();
    DataVector = new Data[dim];
    dimLogQueue = dim;
    for(ulong i =0;i<copyQueue.Size();i++){
        DataVector[i] = copyQueue[i];
    }
    return *this;
}

template<typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec&& copyQueue) noexcept{
    std::swap(dim,copyQueue.dim);
    std::swap(head,copyQueue.head);
    std::swap(DataVector,copyQueue.DataVector);
    std::swap(dimLogQueue,copyQueue.dimLogQueue);
    return *this;
}

template<typename Data>
bool QueueVec<Data>::operator==(const QueueVec& comparisonVector) const noexcept{
    if(dimLogQueue!=comparisonVector.Size()){
        return false;
    }
    int j =head;
    int k = comparisonVector.head;
    for(int i=0;i<dimLogQueue;i++){
        
        if(DataVector[j]!=comparisonVector[k]){
            return false;
        }
        j = (j+1)%dimLogQueue;
        k = (k+1)%dimLogQueue;
    }
    return true;
    /*
    if(dimLogQueue!=comparisonVector.Size()){
        return false;
    }
    for(ulong i =0;i<comparisonVector.Size();i++){ // TODO confronto giusto? mettere dim al posto di comparisonVector.Size()
        if(DataVector[i]!=comparisonVector[i]){
            return false;
        }
    }
    return true;
    */
}



template<typename Data>
bool QueueVec<Data>::operator!=(const QueueVec& comparisonVector)const noexcept{
   return !(*this == comparisonVector);
}

template<typename Data>
Data QueueVec<Data>::Head() const{
    if (dim != 0  && dimLogQueue!=0){
        return DataVector[head];
    }
    else {
        throw std::length_error("Access to an empty stack. ");
    }
}

template<typename Data>
Data& QueueVec<Data>::Head(){
    if (dim != 0  && dimLogQueue!=0){
        return DataVector[head];
    }
    else {
        throw std::length_error("Access to an empty stack. ");
    }
}



template<typename Data>
void QueueVec<Data>::Dequeue(){
    if (dim != 0 && dimLogQueue!=0){
        
        head = (head +1) % dim;
        dimLogQueue--;
        // TODO REDUCE
        if(dimLogQueue<dim/4)
            Reduce();
    }
    else {
        throw std::length_error("Access to an empty stack. ");
    }
}

template<typename Data>
Data QueueVec<Data>::HeadNDequeue(){
    if (dim != 0 && dimLogQueue!=0){
        Data d = Head();
        Dequeue();
        return d;
    }
    else {
        throw std::length_error("Access to an empty stack. ");
    }
}

template<typename Data>
void QueueVec<Data>::Enqueue(const Data& d) noexcept{
    if(dimLogQueue<dim)
    {
        
        if(dimLogQueue == 0)DataVector[0] = d;
        else
        {
            DataVector[(head+dimLogQueue)%dim] = d;
           
        }
         dimLogQueue++;
        
    }
    else
    {
        Expand();
        Enqueue(d);
    }
    
}


template<typename Data>
void QueueVec<Data>::Enqueue(Data&& d) noexcept{
    if(dimLogQueue<dim)
    {
        if(dimLogQueue == 0)DataVector[0] = d;
        else
        {
            DataVector[(head+dimLogQueue)%dim] = d;
           
        }
         dimLogQueue++;
    }
    else
    {
        Expand();
        Enqueue(d);
    }
}
template<typename Data>
bool QueueVec<Data>::Empty() const noexcept{
    return dimLogQueue == 0;
}
template<typename Data>
void QueueVec<Data>::Clear() noexcept{
    Vector<Data>::Clear();
    dimLogQueue = 0;
    head= 0;
}
template<typename Data>
unsigned long QueueVec<Data>::Size() const noexcept{
    return dimLogQueue;
}
template<typename Data>
void QueueVec<Data>::RotateRight(){
    if(dim>1){
        Data temp = DataVector[dim-1]; 
        for(int i=dim-1;i>0;i--){
            DataVector[i] = DataVector[i-1]; 
        }
        DataVector[0] = temp;
    }
}
template<typename Data>
void QueueVec<Data>::Expand() noexcept
{
    Vector<Data>::Resize((dim+1)*2);
    for(int i=0;i<dimLogQueue;i++)
            RotateRight();
    head = head + dimLogQueue%dim;
}
template<typename Data>
void QueueVec<Data>::Reduce() noexcept
{
    Data* temp = new Data[dimLogQueue];
    for(ulong i =0;i<dimLogQueue;i++){
        temp[i] = DataVector[(head+i)%dim];
    }
    head -= dim-dimLogQueue;
    dim = dimLogQueue;
    std::swap(DataVector,temp);
    delete temp;
    //Vector<Data>::Resize(dim/4+1);
}

// swap vectors
template<typename Data>
void QueueVec<Data>::SwapVectors(QueueVec<Data>& a,QueueVec<Data>& b) noexcept{
    std::swap(a.dim,b.dim);
    std::swap(a.head,b.head);
    std::swap(a.DataVector,b.DataVector);
    std::swap(a.dimLogQueue,b.dimLogQueue);
}
template<typename Data>
void QueueVec<Data>::Print()
{
    std::cout<<"queue dim logica = "<<dimLogQueue<<"queue dim ="<<dim<<std::endl;
    for(ulong i =0;i<dimLogQueue;i++){
        std::cout<<DataVector[i]<<" ";
    }
    std::cout<<std::endl;
}
/* ************************************************************************** */

}
