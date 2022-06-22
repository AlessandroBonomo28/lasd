#include <iostream>
namespace lasd {
/* ************************************************************************** */
template <typename Data>
//Specific constructor
Vector<Data>::Vector(const ulong newDim){
  DataVector = new Data[newDim] {};
  dim = newDim;
}
template <typename Data>
Vector<Data>::Vector(const LinearContainer<Data>& copyContainer){
  dim = copyContainer.Size();
  DataVector = new Data[dim];
  for(unsigned int i = 0;i < dim; i++) {
    DataVector[i] = copyContainer[i];
  }
}
//Copy constructor
template <typename Data>
Vector<Data>::Vector(const Vector<Data> &copyVector){
  dim = copyVector.dim;
  DataVector = new Data[dim];
  for(unsigned int i = 0; i < dim; i++) {
    DataVector[i] = copyVector[i];
  }
}

//Move constructor
template <typename Data>
Vector<Data>::Vector(Vector&& copyVector) noexcept{
  std::swap(DataVector, copyVector.DataVector);
  std::swap(dim, copyVector.dim);
}

//Destructor
template <typename Data>
Vector<Data>::~Vector(){
  delete[] DataVector;
  DataVector = nullptr;
}
//Copy assignment
template <typename Data>
Vector<Data>& Vector<Data>::operator=(const Vector<Data>& copyVector){
  Vector<Data>* tempVector = new Vector<Data>(copyVector);
  std::swap(*tempVector, *this);
  delete tempVector;
  return *this;
}
//Move assignment
template <typename Data>
Vector<Data>& Vector<Data>::operator=(Vector<Data>&& moveVector) noexcept{
  std::swap(DataVector, moveVector.DataVector);
  std::swap(dim, moveVector.dim);
  return *this;
}
//Comparison operators
template <typename Data>
bool Vector<Data>::operator==(const Vector<Data>& comparisonVector) const noexcept{
  
  if(dim == comparisonVector.dim){
    for (unsigned int i = 0; i < comparisonVector.dim; i++){
      if(DataVector[i] != comparisonVector[i])
        return false;
      
    }
  }else return false;
  return true;
}
template <typename Data>
bool Vector<Data>::operator!=(const Vector<Data>& comparisonVector) const noexcept{
  return !(*this == comparisonVector);
}
// Specific member functions
template <typename Data>
void Vector<Data>::Resize(const ulong newDim){
  if (newDim == 0 ){
    Clear();
  }
  else if(dim != newDim){
    Data* tempVector = new Data[newDim]{};
    for(unsigned int i = 0; i < newDim; i++){
      if(i < dim){
        tempVector[i] = DataVector[i];
      }
    }
    std::swap(DataVector, tempVector);
    delete [] tempVector;
    dim = newDim;
  }
}

template<typename Data>
void Vector<Data>::Print() const{
  std::cout<<"Printing vec, dim = "<<dim<<std::endl;
  for(unsigned long i = 0; i < dim; i++){
    std::cout<<DataVector[i]<<" ";
  }
  std::cout<<std::endl;
}
// Specific member functions (inherited from Container)
template<typename Data>
void Vector<Data>::Clear(){
  dim = 0;
  delete[] DataVector;
  DataVector = nullptr;
}
// Specific member functions (inherited from LinearContainer)
template<typename Data>
Data& Vector<Data>::Front() const{
  if (dim != 0){
    return DataVector[0];
  }
  else {
    throw std::length_error("Access to an empty linear container. ");
  }
}

template<typename Data>
Data& Vector<Data>::Back() const{
  if (dim != 0){
    return DataVector[dim - 1];
  }
  else {
    throw std::length_error("Access to an empty linear container. ");
  }
}

template<typename Data>
Data& Vector<Data>::operator[](const unsigned long acc) const{
  if (acc < dim){
    return DataVector[acc];
  }
  else{
    throw std::out_of_range("error your are out of size");
  }
}
// Specific member functions (inherited from MappableContainer)
template<typename Data>
void Vector<Data>::Map(MapFunctor function, void* value){
  MapPostOrder(function, value);
}

template<typename Data>
void Vector<Data>::MapPreOrder(MapFunctor function, void* value){
  for(unsigned int i = 0; i < dim; i++){
    function(DataVector[i], value);
  }
}

template<typename Data>
void Vector<Data>::MapPreOrder(MapFunctor function, void* value,unsigned int index){
  if(dim==0)return;
  if(index>=dim){
    throw std::out_of_range("error your are out of size");
  }
  else
  {
    for(unsigned long i = index; i < dim; i++){
        function(DataVector[i], value);
      }
  }
  
}

template<typename Data>//nuovo
  void Vector<Data>::MapPostOrder(MapFunctor function, void* value){
     ulong index = dim;
    while (index > 0) {
        function(DataVector[--index], value);
    }
    /*
    if(dim==0)return;
    for(unsigned int i = (dim -1); i >= 0; i--){
      function(DataVector[i], value);
    }
  */
}
template<typename Data>
  void Vector<Data>::MapPostOrder(MapFunctor function, void* value,unsigned int index){
    // TODO
    if(dim==0)return;
    if(index>=dim){
      throw std::out_of_range("error your are out of size");
    }
    else{
      int i=dim;
      while (i > index) {
        function(DataVector[--i], value);
      }
      /*
      for(unsigned int i = (dim -1); i >= index; i--){
        function(DataVector[i], value);
      }
      */
    }
}
// Specific member functions (inherited from FoldableContainer)
template<typename Data>
void Vector<Data>::Fold(FoldFunctor function, const void* value, void* acc) const{
  if(dim==0)return;
  FoldPostOrder(function, value, acc);
}

template<typename Data>
void Vector<Data>::FoldPreOrder(FoldFunctor function, const void* value, void* acc) const{
  for(unsigned long i = 0; i < dim; i++){
    function(DataVector[i], value, acc);
  }
}
template<typename Data>
void Vector<Data>::FoldPreOrder(FoldFunctor function, const void* value, void* acc,unsigned int index) const{
  //TODO
  for(unsigned long i = index; i < dim; i++){
    function(DataVector[i], value, acc);
  }
}

template<typename Data>
void Vector<Data>::FoldPostOrder(FoldFunctor function, const void* value, void* acc) const{
  if(dim==0)return;
  ulong index = dim;
    while (index > 0) {
        function(DataVector[--index], value, acc);
    }
  /*
  for(unsigned int i = (dim -1); i >= 0; i--){
    function(DataVector[i], value, acc);
  }
  */
}
template<typename Data>
void Vector<Data>::FoldPostOrder(FoldFunctor function, const void* value, void* acc,unsigned int index) const{
  //TODO
  if(dim==0)return;
  ulong i = dim;
    while (i > index) {
        function(DataVector[--i], value, acc);
    }
  /*
  for(unsigned long i = (dim -1); i >= index; i--){
    function(DataVector[i], value, acc);
  }
  */
}
/*************************************************************************** */

}
