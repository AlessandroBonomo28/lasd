
namespace lasd {
/* ************************************************************************** */

//LinearContainer
template<typename Data>
bool LinearContainer<Data>::operator==(const LinearContainer<Data>& linearC) const noexcept{
  if (dim == linearC.dim){
    for (unsigned int i = 0; i < dim; i++){
      if(operator[](i) != linearC[i]){
        return false;
      }
    }
    return true;
  } else {
    return false;
  }
}

template<typename Data>
bool LinearContainer<Data>::operator!=(const LinearContainer<Data>& linearC) const noexcept{
  return !(*this == linearC);
}

template<typename Data>
Data& LinearContainer<Data>::Front() const{
  if (dim != 0){
    return operator[](0);
  }
  else {
    throw std::length_error("Access to an empty linear container. ");
  }
}

template<typename Data>
Data& LinearContainer<Data>::Back() const{
  if (dim != 0){
    return operator[](dim - 1);
  }
  else {
    throw std::length_error("Access to an empty linear container. ");
  }
}


//FoldableContainer

template<typename Data>
void FoldExists(const Data& data, const void* value, void* exists){
  if (data == *((Data*)value)){
    *((bool*) exists) = true;
    }
}

template<typename Data>
bool FoldableContainer<Data>::Exists(const Data& data) const noexcept{
  bool exists = false;
  Fold(&FoldExists<Data>, &data, &exists);
  return exists;
}

// PreOrderMappableConteiner
template<typename Data>
void PreOrderMappableContainer<Data>::Map(MapFunctor function, void* value){
  MapPreOrder(function, value);

}
// PostOrderMappableContainer
template <typename Data>
void PostOrderMappableContainer<Data>::Map(MapFunctor funct, void *opt)
{
    MapPostOrder(funct, opt);
}
//PreOrderFoldableContainer
template<typename Data>
void PreOrderFoldableContainer<Data>::Fold(FoldFunctor function, const void* value, void* acc) const {
  FoldPreOrder(function, value, acc);
}
//PostOrderFoldableContainer
template <typename Data>
    void PostOrderFoldableContainer<Data>::Fold(FoldFunctor funct, const void *init, void *acc) const
    {
        FoldPostOrder(funct, init, acc);
    }


/*
// PreOrderMappableConteiner
template<typename Data>
void PreOrderMappableContainer<Data>::Map(MapFunctor function, void* value){
  MapPreOrder(function, value);

}
// PostOrderMappableContainer
template<typename Data>
void PostOrderMappableContainer<Data>::Map(MapFunctor function, void* value) {
  MapPostOrder(function, value);
}
//PostOrderFoldableContainer
template<typename Data>
void PostOrderFoldableContainer<Data>::Fold(FoldFunctor function, const void* value, void* acc) const{
  FoldPostOrder(function, value);
}
//PreOrderFoldableContainer
template<typename Data>
void PreOrderFoldableContainer<Data>::Fold(FoldFunctor function, const void* value, void* acc) const{
  FoldPreOrder(function, value, acc);
}

*//* ************************************************************************** */

}
