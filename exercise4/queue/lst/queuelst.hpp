
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueLst : virtual public Queue<Data>,
                 virtual public List<Data>
                {
                  // Must extend Queue<Data>,
                  //             List<Data>

private:

  // ...

protected:
  using List<Data>::dim;
  using List<Data>::head;
  using List<Data>::tail;
  struct Node : List<Data>::Node{};
  // using List<Data>::???;

  // ...

public:

  // Default constructor
  // QueueLst() specifier;
  QueueLst() = default;
  /* ************************************************************************ */

  // Specific constructor
  // QueueLst(argument) specifiers; // A queue obtained from a LinearContainer
  QueueLst(const LinearContainer<Data>&); // A queue obtained from a LinearContainer
  /* ************************************************************************ */

  // Copy constructor
  // QueueLst(argument);
  QueueLst(const QueueLst&) noexcept;

  // Move constructor
  // QueueLst(argument);
  QueueLst(QueueLst&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~QueueLst() specifier;
  ~QueueLst() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);
  QueueLst& operator=(const QueueLst&) noexcept;

  // Move assignment
  // type operator=(argument);
  QueueLst& operator=(QueueLst&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const QueueLst&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator!=(const QueueLst&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  // type Head() specifiers; // Override Queue member (constant version; must throw std::length_error when empty)
  Data Head() const override; // Override Queue member (constant version; must throw std::length_error when empty)
  // type Head() specifiers; // Override Queue member (must throw std::length_error when empty)
  Data& Head() override; // Override Queue member (must throw std::length_error when empty)
  // type Dequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  void Dequeue() override; // Override Queue member (must throw std::length_error when empty)
  // type HeadNDequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  Data HeadNDequeue() override; // Override Queue member (must throw std::length_error when empty)
  // type Enqueue(argument) specifiers; // Override Queue member (copy of the value)
  void Enqueue(const Data&) noexcept override; // Override Queue member (copy of the value)
  // type Enqueue(argument) specifiers; // Override Queue member (move of the value)
  void Enqueue(Data&&) noexcept override; // Override Queue member (move of the value)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Clear() specifiers; // Override Container member
  void Clear() override; // Override Container member
};

/* ************************************************************************** */

}

#include "queuelst.cpp"

#endif
