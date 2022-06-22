
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

#include "../iterator/iterator.hpp"

// #include "..."

#include "../stack/lst/stacklst.hpp"
#include "../queue/lst/queuelst.hpp"
/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTree : 
                 virtual public PreOrderMappableContainer<Data>,
                  virtual public PostOrderMappableContainer<Data>,
                  virtual public InOrderMappableContainer<Data>,
                  virtual public BreadthMappableContainer<Data>,
                  virtual public PreOrderFoldableContainer<Data>,
                  virtual public PostOrderFoldableContainer<Data>,
                  virtual public InOrderFoldableContainer<Data>,
                  virtual public BreadthFoldableContainer<Data>{

private:

  // ...

protected:

  // using InOrder/BreadthMappableContainer<Data>::???;

   using InOrderMappableContainer<Data>::dim; 
  // ...

public:

  typedef struct Node {

  private:

    // ...

  protected:
    
    // Comparison operators
    // type operator==(argument) specifiers; // Comparison of abstract types is possible, but should not be visible.
    bool operator==(const Node&) const noexcept; // Comparison of abstract types is possible, but should not be visible.
    // type operator!=(argument) specifiers; // Comparison of abstract types is possible, but should not be visible.
    bool operator!=(const Node&) const noexcept;
    // ...
  public:

    // friend class BinaryTree<Data>;
    friend class BinaryTree<Data>;
    /* ********************************************************************** */
    //virtual Node() =default;
    // Destructor
    virtual ~Node() = default;

    /* ********************************************************************** */
    
    // Copy assignment
    // type operator=(argument); // Copy assignment of abstract types should not be possible.
    Node& operator=(const Node&) noexcept= delete; // Copy assignment of abstract types should not be possible.

    // Move assignment
    // type operator=(argument); // Move assignment of abstract types should not be possible.
    Node& operator=( Node&&) noexcept= delete; // Move assignment of abstract types should not be possible.

    /* ********************************************************************** */

    
    /* ********************************************************************** */

    // Specific member functions

    // type Element() specifiers; // Mutable access to the element (concrete function should not throw exceptions)
    virtual Data& Element() noexcept=0; // Mutable access to the element (concrete function should not throw exceptions)
    // type Element() specifiers; // Immutable access to the element (concrete function should not throw exceptions)
    virtual const Data& Element() const noexcept =0; // Immutable access to the element (concrete function should not throw exceptions)
    // type IsLeaf() specifiers; // (concrete function should not throw exceptions)
    virtual bool IsLeaf() const noexcept=0; // (concrete function should not throw exceptions)
    // type HasLeftChild() specifiers; // (concrete function should not throw exceptions)
    virtual bool HasLeftChild() const noexcept=0; // (concrete function should not throw exceptions)
    // type HasRightChild() specifiers; // (concrete function should not throw exceptions)
    virtual bool HasRightChild() const noexcept=0; // (concrete function should not throw exceptions)

    // type LeftChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
    virtual Node& LeftChild()const =0; // (concrete function must throw std::out_of_range when not existent)
    // type RightChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
    virtual Node& RightChild()const =0; // (concrete function must throw std::out_of_range when not existent)

  }Node;

  /* ************************************************************************ */

  // Destructor
  // ~BinaryTree() specifiers
  virtual ~BinaryTree() noexcept = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  BinaryTree& operator=(const BinaryTree&) noexcept= delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  BinaryTree& operator=( BinaryTree&&) noexcept= delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract binary tree is possible.
  bool operator==(const BinaryTree&) const noexcept; // Comparison of abstract binary tree is possible.
  // type operator!=(argument) specifiers; // Comparison of abstract binary tree is possible.
  bool operator!=(const BinaryTree&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  // type Root() specifiers; // (concrete function must throw std::length_error when empty)
  virtual Node& Root()const=0; // (concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  // using typename MappableContainer<Data>::MapFunctor;
   using typename MappableContainer<Data>::MapFunctor;
  // type Map(arguments) specifiers; // Override MappableContainer member
  void Map(MapFunctor, void*) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

  // using typename FoldableContainer<Data>::FoldFunctor;
  using typename FoldableContainer<Data>::FoldFunctor;
  // type Fold(arguments) specifiers; // Override FoldableContainer member
  void Fold(FoldFunctor, const void*, void*) const override;
  /* ************************************************************************ */

  // Specific member functions (inherited from PreOrderMappableContainer)

  // type MapPreOrder(arguments) specifiers; // Override PreOrderMappableContainer member
  void MapPreOrder(MapFunctor, void*) override;
  void MapPreOrder(MapFunctor, void*,unsigned int) override;
  /* ************************************************************************ */

  // Specific member functions (inherited from PreOrderFoldableContainer)

  // type FoldPreOrder(arguments) specifiers; // Override PreOrderFoldableContainer member
  void FoldPreOrder(FoldFunctor, const void*, void*) const override;
  void FoldPreOrder(FoldFunctor, const void*, void*,unsigned int) const override;
  /* ************************************************************************ */

  // Specific member functions (inherited from PostOrderMappableContainer)

  // type MapPostOrder(arguments) specifiers; // Override PostOrderMappableContainer member
  void MapPostOrder(MapFunctor, void*) override;
  void MapPostOrder(MapFunctor, void*,unsigned int) override;
  /* ************************************************************************ */

  // Specific member functions (inherited from PostOrderFoldableContainer)

  // type FoldPostOrder(arguments) specifiers; // Override PostOrderFoldableContainer member
  void FoldPostOrder(FoldFunctor, const void*, void*) const override;
  void FoldPostOrder(FoldFunctor, const void*, void*,unsigned int) const override;
  /* ************************************************************************ */

  // Specific member functions (inherited from InOrderMappableContainer)

  // type MapInOrder(arguments) specifiers; // Override InOrderMappableContainer member
  void MapInOrder(MapFunctor, void*) override; 

  /* ************************************************************************ */

  // Specific member functions (inherited from InOrderFoldableContainer)

  // type FoldInOrder(arguments) specifiers; // Override InOrderFoldableContainer member
  void FoldInOrder(FoldFunctor, const void*, void*) const override;

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthMappableContainer)

  // type MapBreadth(arguments) specifiers; // Override BreadthMappableContainer member
  void MapBreadth(const MapFunctor, void*) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthFoldableContainer)

  // type FoldBreadth(arguments) specifiers; // Override BreadthFoldableContainer member
  void FoldBreadth(FoldFunctor, const void*, void*) const override;

protected:

  // Auxiliary member functions (for PreOrderMappableContainer)

  // type MapPreOrder(arguments) specifiers; // Accessory function executing from one node of the tree
  void MapPreOrder(MapFunctor, void*,Node* );
  /* ************************************************************************ */

  // Auxiliary member functions (for PreOrderFoldableContainer)

  // type FoldPreOrder(arguments) specifiers; // Accessory function executing from one node of the tree
  void FoldPreOrder(FoldFunctor, const void*, void*,Node* ) const;

  /* ************************************************************************ */

  // Auxiliary member functions (for PostOrderMappableContainer)

  // type MapPostOrder(arguments) specifiers; // Accessory function executing from one node of the tree
  void MapPostOrder(MapFunctor, void*,Node* );

  /* ************************************************************************ */

  // Auxiliary member functions (for PostOrderFoldableContainer)

  // type FoldPostOrder(arguments) specifiers; // Accessory function executing from one node of the tree
  void FoldPostOrder(FoldFunctor, const void*, void*,Node* ) const;

  /* ************************************************************************ */

  // Auxiliary member functions (for InOrderMappableContainer)

  // type MapInOrder(arguments) specifiers; // Accessory function executing from one node of the tree
  void MapInOrder(MapFunctor, void*,Node* );

  /* ************************************************************************ */

  // Auxiliary member functions (for InOrderFoldableContainer)

  // type FoldInOrder(arguments) specifiers; // Accessory function executing from one node of the tree
  void FoldInOrder(FoldFunctor, const void*, void*,Node* ) const;

  /* ************************************************************************ */

  // Auxiliary member functions (for BreadthMappableContainer)

  // type MapBreadth(arguments) specifiers; // Accessory function executing from one node of the tree
  void MapBreadth(MapFunctor, void*,Node* );

  /* ************************************************************************ */

  // Auxiliary member functions (for BreadthFoldableContainer)

  // type FoldBreadth(arguments) specifiers; // Accessory function executing from one node of the tree
  void FoldBreadth(FoldFunctor, const void*, void*,Node* ) const;

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderIterator : public virtual ForwardIterator<Data>,
                           public virtual ResettableIterator<Data>{
                           // Must extend ForwardIterator<Data>,
                           //             ResettableIterator<Data>

private:

  // ...

protected:
  struct BinaryTree<Data>::Node* root = nullptr;
  struct BinaryTree<Data>::Node* current = nullptr;
  StackLst<struct BinaryTree<Data>::Node*> stk;
  // ...

public:

  // Specific constructors
  // BTPreOrderIterator(argument) specifiers; // An iterator over a given binary tree
  BTPreOrderIterator(const BinaryTree<Data>&) ;

  /* ************************************************************************ */

  // Copy constructor
  // BTPreOrderIterator(argument) specifiers;
  BTPreOrderIterator(const BTPreOrderIterator&) ;

  // Move constructor
  // BTPreOrderIterator(argument) specifiers;
  BTPreOrderIterator(BTPreOrderIterator&&) noexcept;


  /* ************************************************************************ */

  // Destructor
  // ~BTPreOrderIterator() specifiers;
  virtual ~BTPreOrderIterator();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTPreOrderIterator& operator=(const BTPreOrderIterator&);

  // Move assignment
  // type operator=(argument) specifiers;
  BTPreOrderIterator& operator=(BTPreOrderIterator&&)noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const BTPreOrderIterator&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator!=(const BTPreOrderIterator&) const noexcept;

  Data& operator*() const override; // (throw std::out_of_range when terminated)

  bool Terminated() const noexcept override; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  BTPreOrderIterator& operator++() override; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
  void Reset() noexcept override;

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderIterator : virtual public ForwardIterator<Data>
                            , virtual public ResettableIterator<Data>{
                            // Must extend ForwardIterator<Data>,
                            //             ResettableIterator<Data>

private:

  // ...
  void getMostLeftLeaf();

protected:
  struct BinaryTree<Data>::Node* root = nullptr;
  struct BinaryTree<Data>::Node* current = nullptr;
  struct BinaryTree<Data>::Node* last = nullptr;
  StackLst<struct BinaryTree<Data>::Node*> stk;
  // ...

public:

  // Specific constructors
  BTPostOrderIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTPostOrderIterator(const BTPostOrderIterator&);

  // Move constructor
  BTPostOrderIterator(BTPostOrderIterator&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BTPostOrderIterator();

  /* ************************************************************************ */

  // Copy assignment
  BTPostOrderIterator& operator=(const BTPostOrderIterator&);

  // Move assignment
  BTPostOrderIterator& operator=(BTPostOrderIterator&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTPostOrderIterator&) const noexcept;
  bool operator!=(const BTPostOrderIterator&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  Data& operator*() const override; // (throw std::out_of_range when terminated)

  bool Terminated() const noexcept override; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  BTPostOrderIterator& operator++() override; // (throw std::out_of_range when terminated)


  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
  void Reset() noexcept override;

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderIterator : virtual public ForwardIterator<Data>
                         , virtual public ResettableIterator<Data>{
                          // Must extend ForwardIterator<Data>,
                          //             ResettableIterator<Data>

private:

  void getMostLeftNode();

protected:
  struct BinaryTree<Data>::Node* root = nullptr;
  struct BinaryTree<Data>::Node* current = nullptr;
  StackLst<struct BinaryTree<Data>::Node*> stk;

public:

  // Specific constructors
  BTInOrderIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTInOrderIterator(const BTInOrderIterator&);

  // Move constructor
  BTInOrderIterator(BTInOrderIterator&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BTInOrderIterator();

  /* ************************************************************************ */

  // Copy assignment
  BTInOrderIterator& operator=(const BTInOrderIterator&);

  // Move assignment
  BTInOrderIterator& operator=(BTInOrderIterator&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTInOrderIterator&) const noexcept;
  bool operator!=(const BTInOrderIterator&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  Data& operator*() const override; // (throw std::out_of_range when terminated)

  bool Terminated() const noexcept override; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  BTInOrderIterator& operator++() override; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
  void Reset() noexcept override;

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthIterator : virtual public ForwardIterator<Data> ,
                          virtual public ResettableIterator<Data>{ // Must extend ForwardIterator<Data>

private:

  // ...

protected:
  struct BinaryTree<Data>::Node* root = nullptr;
  struct BinaryTree<Data>::Node* current = nullptr;
  QueueLst<struct BinaryTree<Data>::Node*> que;

public:

  // Specific constructors
  BTBreadthIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTBreadthIterator(const BTBreadthIterator&);

  // Move constructor
  BTBreadthIterator(BTBreadthIterator&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BTBreadthIterator();

  /* ************************************************************************ */

  // Copy assignment
  BTBreadthIterator& operator=(const BTBreadthIterator&);

  // Move assignment
  BTBreadthIterator& operator=(BTBreadthIterator&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTBreadthIterator&) const noexcept;
  bool operator!=(const BTBreadthIterator&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  Data& operator*() const override; // (throw std::out_of_range when terminated)

  bool Terminated() const noexcept override; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  BTBreadthIterator& operator++() override; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */
  // reset 
  void Reset() noexcept override;
};

/* ************************************************************************** */

}

#include "binarytree.cpp"

#endif
