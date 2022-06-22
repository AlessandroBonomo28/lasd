
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec : virtual public Queue<Data>,
                 virtual public Vector<Data>{
                  // Must extend Queue<Data>,
                  //             Vector<Data>

private:

  // ...

protected:

  // using Vector<Data>::???;
  using Vector<Data>::dim;
  using Vector<Data>::DataVector;
  unsigned long head=0;
  unsigned long dimLogQueue=0;
  // ...

public:

  // Default constructor
  // QueueVec() specifier;
  QueueVec() = default;

  /* ************************************************************************ */

  // Specific constructor
  // QueueVec(argument) specifiers; // A queue obtained from a LinearContainer
  QueueVec(const LinearContainer<Data>&); // A queue obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
  // QueueVec(argument);
  QueueVec(const QueueVec&) noexcept;

  // Move constructor
  // QueueVec(argument);
  QueueVec(QueueVec&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~QueueVec() specifier;
  ~QueueVec() = default;

  /* ************************************************************************ */
  void Print();
  // Copy assignment
  QueueVec& operator=(const QueueVec&) noexcept;
  // type operator=(argument);



  // Move assignment
  QueueVec& operator=( QueueVec&&) noexcept;
  // type operator=(argument);

  /* ************************************************************************ */

  // Comparison operators

  // type operator==(argument) specifiers;
  bool operator==(const QueueVec&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator!=(const QueueVec&) const noexcept;

  /* ************************************************************************ */
  void RotateRight();
  // Specific member functions (inherited from Queue)

  // type Head() specifiers; // Override Queue member (constant version; must throw std::length_error when empty)
  Data Head() const override;
  // type Head() specifiers; // Override Queue member (must throw std::length_error when empty)
  Data& Head() override;
  // type Dequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  void Dequeue() override;
  // type HeadNDequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  Data HeadNDequeue() override;
  // type Enqueue(argument) specifiers; // Override Queue member (copy of the value)
  void Enqueue(const Data&) noexcept override;
  // type Enqueue(argument) specifiers; // Override Queue member (move of the value)
  void Enqueue(Data&&) noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Empty() specifiers; // Override Container member
  bool Empty() const noexcept override;

  // type Size() specifiers; // Override Container member
  unsigned long Size() const noexcept override;

  // type Clear() specifiers; // Override Container member
  void Clear() noexcept override;

protected:

  // Auxiliary member functions

  // type Expand() specifiers;
  void Expand() noexcept;
  // type Reduce() specifiers;
  void Reduce() noexcept;
  // type SwapVectors(arguments) specifiers;
  void SwapVectors(QueueVec&, QueueVec&) noexcept;

};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif
