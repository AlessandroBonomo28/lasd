
#ifndef HTCLSADR_HPP
#define HTCLSADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
#include "../../vector/vector.hpp"
#include "../../bst/bst.hpp"
// #include ...

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableClsAdr :  virtual public HashTable<Data>{ // Must extend HashTable<Data>

private:

  // ...

protected:
  using HashTable<Data>::x;
  using HashTable<Data>::y;
  using HashTable<Data>::dim;
  using HashTable<Data>::buckDim;
  using HashTable<Data>::prime;
  using HashTable<Data>::hash;
  Vector<BST<Data>> buckets;
  // ...

public:

  // Default constructor
  HashTableClsAdr() noexcept;
  ~HashTableClsAdr() = default;
  
  /* ************************************************************************ */


  HashTableClsAdr(const ulong) noexcept; 
  HashTableClsAdr(const LinearContainer<Data>&) noexcept; 
  HashTableClsAdr(const ulong, const LinearContainer<Data>&) noexcept; 

  /* ************************************************************************ */

  // Copy constructor
  // HashTableClsAdr(argument) specifiers;
  HashTableClsAdr(const HashTableClsAdr&) noexcept;


  // Move constructor
  // HashTableClsAdr(argument) specifiers;
  HashTableClsAdr(HashTableClsAdr&&) noexcept;

  /* ************************************************************************ */



  /* ************************************************************************ */

  // Copy assignment
  HashTableClsAdr& operator=(const HashTableClsAdr&) noexcept; 
  // Move assignment

  HashTableClsAdr& operator=( HashTableClsAdr&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HashTableClsAdr&) const noexcept;

  bool operator!=(const HashTableClsAdr&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from HashTable)
  void Resize(const ulong) noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  bool Insert(const Data&) noexcept override;
  
  bool Insert(Data&&) noexcept override;
  
  bool Remove(const Data&) noexcept override;

  void Print() const noexcept override;
  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  // type Exists(argument) specifiers; // Override TestableContainer member
  bool Exists(const Data&) const noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFunctor;

  void Map(MapFunctor, void*) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  void Fold(FoldFunctor, const void*, void*) const override;

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)
  void Clear() noexcept override;

};

/* ************************************************************************** */

}

#include "htclsadr.cpp"

#endif
