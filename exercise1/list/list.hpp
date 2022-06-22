#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class List : virtual public LinearContainer<Data>,
               virtual public PreOrderMappableContainer<Data>,
               virtual public PostOrderMappableContainer<Data>,
               virtual public PreOrderFoldableContainer<Data>,
               virtual public PostOrderFoldableContainer<Data>

  {

  private:
    // ...

  protected:
    using LinearContainer<Data>::dim;

    struct Node
    {

      Data dataList;
      Node *next = nullptr;

      /* ********************************************************************** */

      Node() = default;

      // Specific constructors
      Node(const Data& d)  {dataList = d;}
      Node(Data&&) noexcept;

      Node(const Node& n) {if(n!=nullptr) dataList = n.dataList;}
      Node(Node&&) noexcept;

      /* ********************************************************************** */
      // Copy assignment
      
      

      /* ********************************************************************** */

      // Destructor
      virtual ~Node() = default;

      /* ********************************************************************** */
      Node& operator=(const Node&) noexcept;
      Node& operator=(Node&&) noexcept;
      // Comparison operators
      
      bool operator==(const Node& comparisonList) const noexcept;
      bool operator!=(const Node& comparisonList) const noexcept;
      /* ********************************************************************** */

      // Specific member functions

      // ...
    } ;

    Node *head = nullptr;
    Node *tail = nullptr;

  public:
    // Default constructor
    List() = default;

    /* ************************************************************************ */

    // Specific constructor
    List(const LinearContainer<Data> &); // A list obtained from a LinearContainer

    /* ************************************************************************ */

    // Copy constructor
    List(const ulong);
    List(const List<Data> &);

    // Move constructor
    List( List<Data> &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    virtual ~List();

    /* ************************************************************************ */

    // Copy assignment
    List<Data> &operator=(const List<Data> &)  noexcept;
    List<Data> &operator=( List<Data> &&)  noexcept;
    // Move assignment
    // type operator=(argument) specifiers;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const List<Data> &) const noexcept;
    bool operator!=(const List<Data> &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions

    void InsertAtFront(const Data &); // Copy of the value
    void InsertAtFront(Data &&);      // Move of the value
    void RemoveFromFront();           // (must throw std::length_error when empty)
    Data FrontNRemove();             // (must throw std::length_error when empty)

    void InsertAtBack(const Data &); // Copy of the value
    void InsertAtBack(Data &&);      // Move of the value

    /* ************************************************************************ */

    // Specific member functions (inherited from Container)
    void Clear() override; // Override Container member
    void Print() const ;
    /* ************************************************************************ */

    // Specific member functions (inherited from LinearContainer)

    Data &Front() const override; // Override LinearContainer member (must throw std::length_error when empty)
    Data &Back() const override;  // Override LinearContainer member (must throw std::length_error when empty)

    Data &operator[](ulong) const override; // Override LinearContainer member (must throw std::out_of_range when out of range)

    /* ************************************************************************ */

    // Specific member functions (inherited from MappableContainer)

    using typename MappableContainer<Data>::MapFunctor;

    void Map(MapFunctor, void *) override; // Override MappableContainer member

    /* ************************************************************************ */

    // Specific member functions (inherited from PreOrderMappableContainer)

    void MapPreOrder(MapFunctor, void *) override; // Override PreOrderMappableContainer member
    void MapPreOrder(MapFunctor, void *,Node*);
    /* ************************************************************************ */

    // Specific member functions (inherited from PostOrderMappableContainer)

    void MapPostOrder(MapFunctor, void *) override; // Override PostOrderMappableContainer member
    void MapPostOrder(MapFunctor, void *,Node*);
    /* ************************************************************************ */

    // Specific member functions (inherited from FoldableContainer)

    using typename FoldableContainer<Data>::FoldFunctor;

    void Fold(FoldFunctor, const void *, void *)const override; // Override FoldableContainer member

    /* ************************************************************************ */

    // Specific member functions (inherited from PreOrderFoldableContainer)

    void FoldPreOrder(FoldFunctor, const void *, void *)const override; // Override FoldableContainer member
    void FoldPreOrder(FoldFunctor, const void *, void *,Node*) const;
    /* ************************************************************************ */

    // Specific member functions (inherited from PostOrderFoldableContainer)

    void FoldPostOrder(FoldFunctor, const void *, void *)const override; // Override FoldableContainer member
    void FoldPostOrder(FoldFunctor, const void *, void *,Node*) const;
  protected:
    // Auxiliary member functions (for PreOrderMappableContainer & PostOrderMappableContainer)
    
    void MapPreOrder(MapFunctor, void *, unsigned int) override;  // Accessory function executing from one point of the list onwards
    void MapPostOrder(MapFunctor, void *, unsigned int)  override; // Accessory function executing from one point of the list onwards

    /* ************************************************************************ */

    // Auxiliary member functions (for PreOrderFoldableContainer & PostOrderFoldableContainer)

    void FoldPreOrder(FoldFunctor, const void *, void *, unsigned int) const override;  // Accessory function executing from one point of the list onwards
    void FoldPostOrder(FoldFunctor, const void *, void *, unsigned int) const override; // Accessory function executing from one point of the list onwards
  };

  /* ************************************************************************** */

}

#include "list.cpp"

#endif
