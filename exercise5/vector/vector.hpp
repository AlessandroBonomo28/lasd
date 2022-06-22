
#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Vector : virtual public LinearContainer<Data>,
            virtual public PreOrderMappableContainer<Data>,
            virtual public PostOrderMappableContainer<Data>,
            virtual public PreOrderFoldableContainer<Data>,
            virtual public PostOrderFoldableContainer<Data>
            {

private:

  // ...

protected:

  using LinearContainer<Data>::dim;
  Data* DataVector = nullptr;

public:

  // Default constructor
  Vector() = default;

  /* ************************************************************************ */

  // Specific constructors
  Vector(const ulong);
  Vector(const LinearContainer<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  Vector(const Vector&);

  // Move constructor
  Vector(Vector&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~Vector();

  /* ************************************************************************ */

  // Copy assignment
  Vector& operator=(const Vector&);

  // Move assignment
  Vector& operator=(Vector&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Vector&) const noexcept;
  bool operator!=(const Vector&) const noexcept;

  /* ************************************************************************ */
  void Print() const ;
  // Specific member functions

  void Resize(const ulong);
  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear() override;

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  Data& Front() const override;
  Data& Back() const override;

  Data& operator[](const ulong) const override;
  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFunctor;

  void Map(MapFunctor, void*) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from PreOrderMappableContainer)

  void MapPreOrder(MapFunctor, void*) override;
  void MapPreOrder(MapFunctor, void*,unsigned int) override;
  /* ************************************************************************ */

  // Specific member functions (inherited from PostOrderMappableContainer)

  void MapPostOrder(MapFunctor, void*) override;
  void MapPostOrder(MapFunctor, void*,unsigned int) override;
  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  void Fold(FoldFunctor, const void*, void*) const override;
  /* ************************************************************************ */

  // Specific member functions (inherited from PreOrderFoldableContainer)

  void FoldPreOrder(FoldFunctor, const void*, void*) const override;
  void FoldPreOrder(FoldFunctor, const void*, void*,unsigned int) const override;
  /* ************************************************************************ */

  // Specific member functions (inherited from PostOrderFoldableContainer)

  void FoldPostOrder(FoldFunctor, const void*, void*) const override;
  void FoldPostOrder(FoldFunctor, const void*, void*,unsigned int) const override;
};

/* ************************************************************************** */

}

#include "vector.cpp"

#endif