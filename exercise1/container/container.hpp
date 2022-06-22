
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

#include <stdexcept>
#include <functional>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

class Container {

private:

protected:

unsigned long dim = 0;

public:

  // Destructor
  virtual ~Container() = default;

  // Container() specifiers

  /* ************************************************************************ */

  // Copy assignment
  Container& operator=(const Container&) = delete;

  // Move assignment
  Container& operator=(Container&&) = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator== (const Container&) const noexcept = delete;
  bool operator!= (const Container&) const noexcept = delete;
  /* ************************************************************************ */

  // Specific member functions

   virtual bool Empty() const noexcept {
    return (dim == 0);
  }

  // type Size() specifiers; // (concrete function should not throw exceptions)
   virtual ulong Size() const noexcept {
      return dim;
  }

  virtual void Clear() = 0;

};

/* ************************************************************************** */

template <typename Data>
class LinearContainer : virtual public Container {

private:

protected:

public:

  // Destructor
  virtual ~LinearContainer() = default;

  /* *************************************************************************/

  // Copy assignment
  LinearContainer& operator=(const LinearContainer&) = delete;

  // Move assignment
  LinearContainer& operator=(LinearContainer&&)  = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const LinearContainer&) const noexcept;
  bool operator!=(const LinearContainer&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions


  virtual Data& Front() const;
  virtual Data& Back() const;

  virtual Data& operator[](ulong) const = 0;
  
};

/* ************************************************************************** */

template <typename Data>
class TestableContainer : virtual public Container{

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~TestableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  bool operator=(const TestableContainer&) noexcept = delete;

  // Move assignment
  bool operator=(TestableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const TestableContainer&) const noexcept = delete;
  bool operator!=(const TestableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  virtual bool Exists(const Data&) const noexcept = 0; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class MappableContainer : virtual public Container {

private:

protected:

public:

  // Destructor
  virtual ~MappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  MappableContainer& operator=(const MappableContainer&) noexcept = delete;

  // Move assignment
  MappableContainer& operator=(MappableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const MappableContainer&) const noexcept = delete;
  bool operator!=(const MappableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  typedef std::function<void(Data&, void*)> MapFunctor;

  virtual void Map(MapFunctor, void*) = 0;

};

/* ************************************************************************** */

template <typename Data>
class FoldableContainer : virtual public TestableContainer<Data>{

private:

protected:

public:

  // Destructor
  ~FoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  FoldableContainer& operator=(const FoldableContainer&) = delete;

  // Move assignment
  FoldableContainer& operator=(FoldableContainer&&) noexcept = delete;
  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const FoldableContainer&) const noexcept = delete;
  bool operator!=(const FoldableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  typedef std::function<void(const Data&, const void*, void*)> FoldFunctor;
  virtual void Fold(FoldFunctor, const void*, void*) const=0;

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  virtual bool Exists(const Data&) const noexcept override;

};

/* ************************************************************************** */

template <typename Data>
class PreOrderMappableContainer : virtual public MappableContainer<Data> { // Must extend MappableContainer<Data>

private:

protected:

public:

  // Destructor
  virtual ~PreOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PreOrderMappableContainer& operator=(const PreOrderMappableContainer&) = delete;
  // Move assignment
  PreOrderMappableContainer& operator=(PreOrderMappableContainer&&) noexcept = delete;


  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PreOrderMappableContainer&) const noexcept = delete;
  bool operator!=(const PreOrderMappableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  using typename MappableContainer<Data>::MapFunctor;

  virtual void MapPreOrder(MapFunctor, void*) = 0;
  virtual void MapPreOrder(MapFunctor, void*,unsigned int) = 0;
  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  virtual void Map(MapFunctor, void*) =0;

};

/* ************************************************************************** */

template <typename Data>
class PreOrderFoldableContainer : virtual public FoldableContainer<Data> {
private:

protected:

public:

  // Destructor
  virtual ~PreOrderFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PreOrderFoldableContainer& operator=(const PreOrderFoldableContainer&) = delete;
  // Move assignment
  PreOrderFoldableContainer& operator=(PreOrderFoldableContainer&&) const noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PreOrderFoldableContainer&) const noexcept = delete;
  bool operator!=(const PreOrderFoldableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void FoldPreOrder(FoldFunctor, const void*, void*) const =0;
  virtual void FoldPreOrder(FoldFunctor, const void*, void*,unsigned int) const =0;
  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

  virtual void Fold(FoldFunctor, const void*, void*) const =0;

};

/* ************************************************************************** */

template <typename Data>
class PostOrderMappableContainer : virtual public MappableContainer<Data> {

private:

protected:

public:

  // Destructor
  virtual ~PostOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PostOrderMappableContainer& operator=(const PostOrderMappableContainer&) = delete;
  // Move assignment
  PostOrderMappableContainer& operator=(PostOrderMappableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PostOrderMappableContainer&) const noexcept = delete;
  // type operator!=(argument) specifiers;
  bool operator!=(const PostOrderMappableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  using typename MappableContainer<Data>::MapFunctor;

  virtual void MapPostOrder(MapFunctor, void*) = 0;
  virtual void MapPostOrder(MapFunctor, void*, unsigned int) = 0;
  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

 virtual void Map(MapFunctor, void*) =0;

};

/* ************************************************************************** */

template <typename Data>
class PostOrderFoldableContainer : virtual public FoldableContainer<Data> {

private:

protected:

public:

  // Destructor
  virtual ~PostOrderFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
PostOrderFoldableContainer& operator=(const PostOrderFoldableContainer&) = delete;
  // Move assignment
PostOrderFoldableContainer& operator=(PostOrderFoldableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
bool operator==(const PostOrderFoldableContainer&) const noexcept = delete;
bool operator!=(const PostOrderFoldableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void FoldPostOrder(FoldFunctor, const void*, void*) const =0;
  virtual void FoldPostOrder(FoldFunctor, const void *, void *, unsigned int) const=0;
  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)
  
  virtual void Fold(FoldFunctor, const void*, void*) const =0;

};

/* ************************************************************************** */

template <typename Data>
class InOrderMappableContainer : virtual public MappableContainer<Data> {

private:

protected:

public:

 //  // Destructor
 //  virtual ~InOrderMappableContainer() = delete;
 //
 //  /* ************************************************************************ */
 //
 //  // Copy assignment
 // InOrderMappableContainer& operator=(const InOrderMappableContainer&) = delete;
 //  // Move assignment
 // InOrderMappableContainer& operator=(InOrderMappableContainer&&) noexcept = delete;
 //
 //  /* ************************************************************************ */
 //
 //  // Comparison operators
 // bool operator==(const InOrderMappableContainer&) const noexcept = delete;
 // bool operator!=(const InOrderMappableContainer&) const noexcept = delete;
 //  /* ************************************************************************ */
 //
 //  // Specific member functions
 //
 // using typename MappableContainer<Data>::MapFunctor;
 //
 //  virtual void MapInOrder(MapFunctor, void*) = 0;
 //
 //  /* ************************************************************************ */
 //
 //  // Specific member functions (inherited from MappableContainer)
 //
 //  inline virtual void Map(MapFunctor, void*) override;

};

/* ************************************************************************** */

template <typename Data>
class InOrderFoldableContainer : virtual public FoldableContainer<Data>{

private:

protected:

public:

  // // Destructor
  // virtual ~InOrderFoldableContainer() = delete;
  //
  // /* ************************************************************************ */
  //
  // // Copy assignment
  // InOrderFoldableContainer& operator=(const InOrderFoldableContainer&) = delete;
  // // Move assignment
  // InOrderFoldableContainer& operator=(InOrderFoldableContainer&) noexcept = delete;
  //
  // /* ************************************************************************ */
  //
  // // Comparison operators
  // bool operator==(const InOrderFoldableContainer&) const noexcept = delete;
  // bool operator!=(const InOrderFoldableContainer&) const noexcept = delete;
  //
  // /* ************************************************************************ */
  //
  // // Specific member functions
  //
  // using typename MappableContainer<Data>::MapFunctor;
  //
  // virtual void FoldInOrder(MapFunctor, const void*, void*) = 0;
  //
  // /* ************************************************************************ */
  //
  // // Specific member functions (inherited from FoldableContainer)
  //
  // inline virtual void Fold(MapFunctor, const void*, void*) override;

};

/* ************************************************************************** */

template <typename Data>
class BreadthMappableContainer : virtual public MappableContainer<Data> {

private:

protected:

public:

  // // Destructor
  // virtual ~BreadthMappableContainer() = default;
  //
  // /* ************************************************************************ */
  //
  // // Copy assignment
  // BreadthMappableContainer& operator=(const BreadthMappableContainer&) = delete;
  // // Move assignment
  // BreadthMappableContainer& operator=(BreadthMappableContainer&) noexcept = delete;
  //
  // /* ************************************************************************ */
  //
  // // Comparison operators
  // bool operator==(const BreadthMappableContainer&) const noexcept = delete;
  // bool operator!=(const BreadthMappableContainer&) const noexcept = delete;
  // /* ************************************************************************ */
  //
  // // Specific member functions
  //
  // using typename MappableContainer<Data>::MapFunctor;
  //
  // virtual void MapBreadth(MapFunctor, void*) = 0;
  //
  // /* ************************************************************************ */
  //
  // // Specific member functions (inherited from MappableContainer)
  //
  // inline virtual void Map(MapFunctor, void*) override;

};

/* ************************************************************************** */

template <typename Data>
class BreadthFoldableContainer { // Must extend FoldableContainer<Data>

private:

protected:

public:

  // // Destructor
  // virtual ~BreadthFoldableContainer() = default;
  //
  // /* ************************************************************************ */
  //
  // // Copy assignment
  // BreadthFoldableContainer& operator=(const BreadthFoldableContainer&) = delete;
  //
  // // Move assignment
  // BreadthFoldableContainer& operator=(BreadthFoldableContainer&) noexcept = delete;
  //
  // /* ************************************************************************ */
  //
  // // Comparison operators
  // bool operator==(const BreadthFoldableContainer&) const noexcept = delete;
  // bool operator!=(const BreadthFoldableContainer&) const noexcept = delete;
  //
  // /* ************************************************************************ */
  //
  // // Specific member functions
  //
  // using typename FoldableContainer<Data>::FoldFunctor;
  //
  // virtual void FoldBreadth(FoldFunctor, void*) = 0;
  //
  // /* ************************************************************************ */
  //
  // // Specific member functions (inherited from FoldableContainer)
  //
  // inline virtual void Fold(FoldFunctor, void*) override;

};

/* ************************************************************************** */

}

#include "container.cpp"

#endif
