
#ifndef HTOPNADR_HPP
#define HTOPNADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
// #include ...

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableOpnAdr : virtual public HashTable<Data> { // Must extend HashTable<Data>

private:

  // ...

protected:

  using HashTable<Data>::dim;
  using HashTable<Data>::buckDim;
  using HashTable<Data>::x;
  using HashTable<Data>::y;
  using HashTable<Data>::prime;
  using HashTable<Data>::hash;
  using HashTable<Data>::cancellati;
  Vector<Data> vector;
  Vector<char> flags;
  // ...

public:

  // Default constructor
   HashTableOpnAdr() noexcept;

  /* ************************************************************************ */

  // Specific constructors
  HashTableOpnAdr(const ulong) noexcept; 
  HashTableOpnAdr(const LinearContainer<Data>&) noexcept; 
  HashTableOpnAdr(const ulong, const LinearContainer<Data>&) noexcept; 

  /* ************************************************************************ */

  // Copy constructor
  HashTableOpnAdr(const HashTableOpnAdr&) noexcept;

  // Move constructor
  HashTableOpnAdr(HashTableOpnAdr&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~HashTableOpnAdr() = default;

  /* ************************************************************************ */

  // Copy assignment
  HashTableOpnAdr& operator=(const HashTableOpnAdr&) noexcept;

  // Move assignment
  HashTableOpnAdr& operator=(HashTableOpnAdr&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HashTableOpnAdr&) const noexcept;
  bool operator!=(const HashTableOpnAdr&) const noexcept;

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

public:

  // Auxiliary member functions

  ulong HashKey(const ulong&, const ulong&) const;
  ulong  Find(const Data&) const noexcept;
  ulong  FindEmpty(ulong &) const noexcept;

};

/* ************************************************************************** */

}

#include "htopnadr.cpp"

#endif
