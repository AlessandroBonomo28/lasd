
namespace lasd {

/* ************************************************************************** */
template<typename Data>
StackVec<Data>::StackVec(const LinearContainer<Data> & copyContainer){
    DataVector = new Data[copyContainer.Size()];
    dim = copyContainer.Size();
    //dimLogStack = dim;
    for(ulong i =0;i<dim;i++){
        Push(copyContainer[i]);
    }
}

template<typename Data>
StackVec<Data>::StackVec(const StackVec<Data>& copyStack) noexcept{
    
    DataVector = new Data[copyStack.dimLogStack];
    dim = copyStack.dimLogStack;
    dimLogStack = copyStack.dimLogStack;
    for(ulong i =0;i<dim;i++){
        DataVector[i] = copyStack.DataVector[i];
    }
    
}

template<typename Data>
StackVec<Data>::StackVec(StackVec<Data>&& copyStack) noexcept{
    std::swap(DataVector,copyStack.DataVector);
    std::swap(dim,copyStack.dim);
    std::swap(dimLogStack,copyStack.dimLogStack);
}



template<typename Data>
StackVec<Data>::~StackVec(){
    delete [] DataVector;
    DataVector = nullptr;
}

template<typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec& copyStack) noexcept{
    
    DataVector = new Data[copyStack.dimLogStack];
    dim = copyStack.dimLogStack;
    dimLogStack = copyStack.dimLogStack;
    for(ulong i =0;i<dim;i++){
        DataVector[i] = copyStack.DataVector[i];
    }
    return *this;
}

template<typename Data>
StackVec<Data>& StackVec<Data>::operator=(StackVec&& copyStack) noexcept{
    std::swap(DataVector,copyStack.DataVector);
    std::swap(dim,copyStack.dim);
    std::swap(dimLogStack,copyStack.dimLogStack);
    return *this;
}

template<typename Data>
bool StackVec<Data>::operator==(const StackVec& comparisonVector) const noexcept{
    //cout both sizes
    //std::cout<<"dim: "<<dimLogStack<<" comparisonVector.dim: "<<comparisonVector.dimLogStack<<std::endl;

   
    if(dimLogStack == comparisonVector.dimLogStack){
        for (unsigned long i = 0; i < comparisonVector.dimLogStack; ++i){
            if(DataVector[i] != comparisonVector[i])
                return false;
        }
    }else return false;
    return true;
}

template<typename Data>
bool StackVec<Data>::operator!=(const StackVec& comparisonVector)const noexcept{
   return !(*this == comparisonVector);
}

template<typename Data>
Data StackVec<Data>::Top() const{
    if (dim != 0 && dimLogStack!=0){
        return DataVector[0];
    }
    else {
        throw std::length_error("Access to an empty stack. ");
    }
}

template<typename Data>
Data& StackVec<Data>::Top(){
    if (dim != 0 && dimLogStack!=0){
        return DataVector[0];
    }
    else {
        throw std::length_error("Access to an empty stack. ");
    }
}

template<typename Data>
void StackVec<Data>::ShiftLeft(){
    if(dim>1)
    {
        //Data temp = DataVector[0]; 
        for(ulong i=0;i<dim-1;i++)
        {
            DataVector[i] = DataVector[i+1]; 
        }
    }
    
}

template<typename Data>
void StackVec<Data>::ShiftRight(){
    if(dim>1)
    {
        //std::cout<<"shift dx dim "<<dim<<std::endl;
        //Data temp = DataVector[dim-1]; 
        for(int i=dim-1;i>0;i--)
        {
            DataVector[i] = DataVector[i-1]; 
        }
    }
    
}

template<typename Data>
void StackVec<Data>::Pop(){
    if (dim != 0 && dimLogStack!=0){
        ShiftLeft();
        dimLogStack--;
        if(dimLogStack < dim/4)
            Reduce();
    }
    else {
        throw std::length_error("Access to an empty stack. ");
    }
}

template<typename Data>
Data StackVec<Data>::TopNPop(){
    if (dim != 0 && dimLogStack!=0){
        Data d = Top();
        Pop();
        return d;
    }
    else {
        throw std::length_error("Access to an empty stack. ");
    }
}

template<typename Data>
void StackVec<Data>::Push(const Data& d) noexcept{
if ( dimLogStack<dim){
        ShiftRight();
        DataVector[0] = d;
        dimLogStack++;
    }
else {
        Expand();
        Push(d);
    }
}

template<typename Data>
void StackVec<Data>::Push(Data&& d) noexcept{
    if ( dimLogStack<dim){
        
            ShiftRight();
            DataVector[0] = std::move(d);
            //std::swap(DataVector[0] ,d);
            dimLogStack++;
        }
    else {
            Expand();
            Push(d);
        }
}

template<typename Data>
bool StackVec<Data>::Empty() const noexcept{
    return(dimLogStack == 0);
}

template<typename Data>
unsigned long StackVec<Data>::Size() const noexcept{
    return dimLogStack;
}

template<typename Data>
void StackVec<Data>::Clear(){
    ulong  x = dimLogStack;
    for(ulong i=0; i<x;i++ )
        Pop();
}
template<typename Data>
void StackVec<Data>::Print(){
    std::cout<<"dim logica= "<<dimLogStack<<" dim fisica="<<dim<<std::endl;
    for(ulong i=0; i<dimLogStack;i++ )
        std::cout<<DataVector[i]<<" ";
    std::cout<<std::endl;
    
}

template<typename Data>
void StackVec<Data>::Expand() noexcept{
    //std::cout<<" old size = "<<dim<<std::endl;
    //std::cout<<" old sizestack = "<<dimLogStack<<std::endl;
    Vector<Data>::Resize((dim+1)*2);
    //std::cout<<" new size = "<<dim<<std::endl;
    //std::cout<<" new sizestack = "<<dimLogStack<<std::endl;
}
    
template<typename Data>
void StackVec<Data>::Reduce()noexcept{
    Vector<Data>::Resize(dim/4+1);
}
}