
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/* ************************************************************************** */

#include <random>

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Hash {

public:
  
  // type operator()(argument) specifiers; // (concrete function should not throw exceptions)
  unsigned long operator()(const Data& data) const noexcept;

};



/* ************************************************************************** */

template <typename Data>
class HashTable : virtual public DictionaryContainer<Data>,
                  virtual public  MappableContainer<Data>,
                  virtual public  FoldableContainer<Data>{
                  // Must extend DictionaryContainer<Data>,
                  //             MappableContainer<Data>,
                  //             FoldableContainer<Data>

private:

  // ...

protected:
  
  Hash<Data> hash;
  using DictionaryContainer<Data>::dim;
  ulong x = 0; 
  ulong y = 0;
  ulong cancellati = 0;
  ulong buckDim = 4489; // size of the table (num of buckets) // primo al quadrato
  ulong prime = 134217943; // prime number
  // ...

public:
  HashTable() {
    
    x = getRand(1);
    y = getRand(0);
  }
  // Destructor
   ~HashTable() =default;

  /* ************************************************************************ */
  //copy constructor
  HashTable(const HashTable&) noexcept;
  //move constructor
  HashTable(HashTable&&) noexcept;

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  HashTable& operator=(const HashTable&) =delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  HashTable& operator=(HashTable&&) =delete;

  /* ************************************************************************ */

  // Comparison operators TODO
  // type operator==(argument) specifiers; // Comparison of abstract binary tree is possible.
  bool operator==(const HashTable&) =delete;
  // type operator!=(argument) specifiers; // Comparison of abstract binary tree is possible.
  bool operator!=(const HashTable&) =delete;
  /* ************************************************************************ */

  // Specific member function

  // type Resize(argument) specifiers; // Resize the hashtable to a given size
  virtual void Resize(const ulong) noexcept=0;
  virtual void Print() const noexcept=0;
protected:

  // Auxiliary member functions

  // type HashKey(argument) specifiers;
  ulong HashKey(const Data&) const;
  ulong getRand(ulong min);
};

/* ************************************************************************** */

}

#include "hashtable.cpp"

#endif
