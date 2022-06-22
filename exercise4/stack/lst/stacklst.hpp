
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackLst : virtual public Stack<Data>,
                 virtual public List<Data>
                 {
                  // Must extend Stack<Data>,
                  //             List<Data>

private:

  // ...

protected:

  // using List<Data>::???;
  using List<Data>::dim;
  using List<Data>::head;
  using List<Data>::tail;
  struct Node : List<Data>::Node{};
  
  
  // ...

public:

  // Default constructor
   StackLst() =default;

  /* ************************************************************************ */

  // Specific constructor
   StackLst(const LinearContainer<Data>&); // A stack obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
   StackLst(const StackLst&) noexcept;

  // Move constructor
   StackLst(StackLst&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~StackLst() = default;

  /* ************************************************************************ */

  // Copy assignment
  StackLst& operator=(const StackLst&) noexcept;

  // Move assignment
  StackLst& operator=( StackLst&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const StackLst&) const noexcept;
  bool operator!=(const StackLst&)  const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  Data Top() const override; // Override Stack member (constant version; must throw std::length_error when empty)
  Data& Top() override; // Override Stack member (must throw std::length_error when empty)
  void Pop() override; // Override Stack member (must throw std::length_error when empty)
  Data TopNPop() override; // Override Stack member (must throw std::length_error when empty)
  void Push(const Data&) noexcept override; // Override Stack member (copy of the value)
  void Push(Data&&) noexcept override; // Override Stack member (move of the value)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear() override; // Override Container member

};

/* ************************************************************************** */

}

#include "stacklst.cpp"

#endif
