
#ifndef ITERATOR_HPP
#define ITERATOR_HPP

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Iterator {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~Iterator() =default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  Iterator& operator=(const Iterator&) noexcept= delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  Iterator& operator=( Iterator&&) noexcept= delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator==(const Iterator&) const noexcept = delete; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator!=(const Iterator&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  // type operator*() specifiers; // (concrete function must throw std::out_of_range when terminated)
  virtual Data& operator*()const =0; // (concrete function must throw std::out_of_range when terminated)
  // type Terminated() specifiers; // (concrete function should not throw exceptions)
  virtual bool Terminated() const noexcept =0; // (concrete function should not throw exceptions)
};

/* ************************************************************************** */

template <typename Data>
class ForwardIterator : virtual public Iterator<Data>{ // Must extend Iterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~ForwardIterator() specifiers
  virtual ~ForwardIterator()  =default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  ForwardIterator& operator=(const ForwardIterator&) noexcept= delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  ForwardIterator& operator=( ForwardIterator&&) noexcept= delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator==(const ForwardIterator&) const noexcept = delete; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator!=(const ForwardIterator&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  // type operator++() specifiers; // (concrete function must throw std::out_of_range when terminated)
  virtual ForwardIterator& operator++() =0; // (concrete function must throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BackwardIterator : virtual public Iterator<Data>{ // Must extend Iterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~BackwardIterator() specifiers
  virtual ~BackwardIterator()  =default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  BackwardIterator& operator=(const BackwardIterator&) noexcept= delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  BackwardIterator& operator=( BackwardIterator&&) noexcept= delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator==(const BackwardIterator&) const noexcept = delete; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator!=(const BackwardIterator&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  // type operator--() specifiers; // (concrete function must throw std::out_of_range when terminated)
  virtual BackwardIterator& operator--() =0; // (concrete function must throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BidirectionalIterator : virtual public ForwardIterator<Data>,
                              virtual public BackwardIterator<Data>{
                              // Must extend ForwardIterator<Data>,
                              //             BackwardIterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~BidirectionalIterator() specifiers
  virtual ~BidirectionalIterator()  =default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  BidirectionalIterator& operator=(const BidirectionalIterator&) noexcept= delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  BidirectionalIterator& operator=( BidirectionalIterator&&) noexcept= delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator==(const BidirectionalIterator&) const noexcept = delete; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator!=(const BidirectionalIterator&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  // type Terminated() specifiers; // Override Iterator member
  virtual bool Terminated() const noexcept override=0; // Override Iterator member

  // type ForwardTerminated() specifiers; // (concrete function should not throw exceptions)
  virtual bool ForwardTerminated() const noexcept =0; // (concrete function should not throw exceptions)

  // type BackwardTerminated() specifiers; // (concrete function should not throw exceptions)
  virtual bool BackwardTerminated() const noexcept =0; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class ResettableIterator : virtual public Iterator<Data>{ // Must extend Iterator<Data>

private:

protected:

public:

  // Destructor
  // ~ResettableIterator() specifiers
  virtual ~ResettableIterator()  =default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  ResettableIterator& operator=(const ResettableIterator&) noexcept= delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  ResettableIterator& operator=( ResettableIterator&&) noexcept= delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator==(const ResettableIterator&) const noexcept = delete; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator!=(const ResettableIterator&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  // type Reset() specifiers; // (concrete function should not throw exceptions)
  virtual void Reset()noexcept =0; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

}

#endif
