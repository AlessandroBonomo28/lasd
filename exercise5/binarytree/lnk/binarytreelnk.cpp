#include <stdexcept>

namespace lasd {

/* ************************************************************************** */
/*                              NODE  LINK                                    */
/* ************************************************************************** */

//Constructor
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data &d) {
    element=d;
    leftchild = nullptr;
    rightchild = nullptr;
}

//Destructor
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::~NodeLnk() {
    
    if(leftchild != nullptr)
    {
        delete leftchild;
        leftchild = nullptr;
    }
    if(rightchild != nullptr)
    {
        delete rightchild;
        rightchild = nullptr;  
    }
}

// Specific member functions
template <typename Data>
Data& BinaryTreeLnk<Data>::NodeLnk::Element() noexcept {
    return element;
}

template <typename Data>
const Data& BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept {
    return element;
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept {
    return (leftchild!=nullptr);
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept {
    return (rightchild!=nullptr);
}

template <typename Data>
struct BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::LeftChild() const {
    if(leftchild==nullptr)
        throw std::out_of_range("Access to an empty child.");

    return *leftchild;
}

template <typename Data>
struct BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::RightChild() const {
    if(rightchild==nullptr)
        throw std::out_of_range("Access to an empty child.");

    return *rightchild;
}

/* ************************************************************************** */
/*                              TREE  LINK                                    */
/* ************************************************************************** */

//Funzioni accessorie
template <typename Data>
void BinaryTreeLnk<Data>::funzioneCostruzione(int index, struct BinaryTreeLnk<Data>::NodeLnk *node, const LinearContainer<Data> &con) {
    if( (index*2 + 1) <= (con.Size()-1)){ // se esiste il figlio sx
        node->leftchild = new NodeLnk(con[index*2 + 1]);
        funzioneCostruzione(index*2 + 1, node->leftchild, con);
    }

    if( (index*2 + 2) <= (con.Size()-1)){ // se esiste il figlio dx
        node->rightchild = new NodeLnk(con[index*2 + 2]);
        funzioneCostruzione(index*2 + 2, node->rightchild, con);
    }
}

template <typename Data>
struct BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::copyTree(NodeLnk *nodeCopy) {
    NodeLnk* node = nullptr;

    if(nodeCopy!=nullptr){
        node = new NodeLnk(nodeCopy->element);

        if(nodeCopy->leftchild!=nullptr)
            node->leftchild = copyTree(nodeCopy->leftchild);

        if(nodeCopy->rightchild!=nullptr)
            node->rightchild = copyTree(nodeCopy->rightchild);
    }

    return node;
}

/* ************************************************************************** */

// Specific constructors
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const LinearContainer<Data> &con) {
    dim = con.Size();
    root = new BinaryTreeLnk<Data>::NodeLnk(con[0]);
    funzioneCostruzione(0, root, con); // costruisce prima tutti i figli sx e poi i dx
}

/* ************************************************************************ */

// Copy constructor
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk<Data> &bt) {
    dim=bt.dim;

    if(dim>0)
        root = copyTree(bt.root);
}

// Move constructor
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk<Data> &&bt) noexcept : BinaryTreeLnk<Data>()  {
    std::swap(root,bt.root);
    std::swap(dim,bt.dim);
}
template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::IsLeaf() const noexcept {
    return !HasLeftChild() && !HasRightChild();
}
/* ************************************************************************ */

// Destructor
template <typename Data>
BinaryTreeLnk<Data>::~BinaryTreeLnk() {
    Clear();
}

/* ************************************************************************ */

// Copy assignment
template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk<Data> &bt) {
    if(bt.dim!=0){
        BinaryTreeLnk<Data>* tmpbt = new BinaryTreeLnk<Data>(bt);
	    std::swap(*tmpbt, *this);
	    delete tmpbt;
    }else{
        Clear();
    }
    return *this;
}

// Move assignment
template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk<Data> &&bt) noexcept {
    std::swap(root,bt.root);
    std::swap(dim,bt.dim);
    return *this;
}

/* ************************************************************************ */

// Comparison operators
template <typename Data>
bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk<Data> &bt) const noexcept {
    return BinaryTree<Data>::operator==(bt);
}

template <typename Data>
bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk<Data> &bt) const noexcept {
    return !(*this == bt);
}

/* ************************************************************************ */

// Specific member functions (inherited from BinaryTree)
template <typename Data>
struct BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::Root() const {
    if(root==nullptr)
        throw std::length_error("Access to an empty tree.");

    return *root;
}
/* ************************************************************************ */

// Specific member functions (inherited from Container)
template <typename Data>
void BinaryTreeLnk<Data>::Clear() {
    dim=0;
    delete root;
    root = nullptr;
}

/* ************************************************************************** */

}
