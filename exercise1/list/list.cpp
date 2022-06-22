
//#include "list.hpp"
#include <iostream>
namespace lasd
{

    /* ************************************************************************** */

    template <typename Data>
    List<Data>::List(const LinearContainer<Data> &linearC){
        for (unsigned long i = 0; i < linearC.Size(); i++){
            InsertAtBack(linearC[i]);
        }
    }

    template <typename Data>
    List<Data>::List( List<Data> &&moveList) noexcept{
        // TODO: Implementare
        std::swap(dim,moveList.dim);
        std::swap(head,moveList.head);
        std::swap(tail,moveList.tail);
    }

    template <typename Data>
    List<Data>::List(const List<Data> &copyList)  {
        
        if(copyList.dim!=0)
        {
            Node* temp = copyList.head;
           
            while (temp != nullptr){
                InsertAtBack(temp->dataList);
                temp = temp->next;
            }

        }
        
    }
    template <typename Data>
    List<Data>::List(const ulong newDim){
        for(unsigned long i = 0; i < newDim; i++){
            InsertAtBack(Data());
        }
    }
    // PER COPIA
    template <typename Data>
    List<Data> &List<Data>::operator=(const List<Data> &copyList)  noexcept{
        Clear();
        if(copyList.dim!=0)
        {
            Node* tempNode = copyList.head;
            
            while (tempNode != nullptr){
                InsertAtBack(tempNode->dataList);
                tempNode = tempNode->next;
            }
            
        }
        
        return *this;
    }
    // PER MOVE
    template <typename Data>
    List<Data> &List<Data>::operator=( List<Data> &&copyList)  noexcept{
        std::swap(head,copyList.head);
        std::swap(tail,copyList.tail);
        std::swap(dim,copyList.dim);
        
        return *this;
    }


    template <typename Data>
    List<Data>::~List(){
        Clear();
        
        delete head;
        delete tail;
        head = nullptr;
        tail=nullptr;  
    }
   
    template <typename Data>
    List<Data>::Node::Node( Data &&d)noexcept{
        std::swap(dataList,d);
        //dataList = std::move(d);
    }

    template <typename Data>
    List<Data>::Node::Node(Node &&d) noexcept{
        if(d!=nullptr){

            std::swap(dataList,d.dataList);
            std::swap(dataList.next,d.next);
        }
       
    }
    
    template <typename Data>
    bool List<Data>::Node::operator==(const Node &d)const noexcept{
       return (dataList == d.dataList) \
            && ((next == nullptr && d.next == nullptr) || (next != nullptr && d.next != nullptr) && (*next == *d.next));
       
    }

    template <typename Data>
    bool List<Data>::Node::operator!=(const Node &d)const noexcept{
       return !(*this == d);
    }
    

    template <typename Data>
    void List<Data>::InsertAtFront(const Data &newData){
        if (head == nullptr){
            head = new Node(newData);
            tail = head;
        }
        else{
            Node *newNode = new Node(newData);
            newNode->next = head;
            head = newNode;
        }
        dim++;
    }

    template<typename Data>
    void List<Data>::InsertAtFront(Data && dat) {
        if (head == nullptr){
            Node* node = new Node();
            node->dataList = std::move(dat);
            head = node;
            tail = head;
        }
        else{
            Node* node = new Node();
            node->dataList = std::move(dat);
            node->next = head;
            head = node;
        }
        dim++;
    }

    template <typename Data>
    void List<Data>::RemoveFromFront(){
        if (dim == 0 )
            throw std::length_error("The List is empty");
        else{
            Node *temp = head;
            head = head->next;
            delete temp;
            dim--;
        }

        
    }

    template <typename Data>
    Data List<Data>::FrontNRemove(){
        if (dim == 0)
            throw std::length_error("The List is empty");
        else
        {
            Data d = Front();
            
            //Node *temp = head;
            //Data& returnedData = temp->dataList;
            
            RemoveFromFront();

            return d;
        }
        
    }
    template <typename Data>
    void List<Data>::InsertAtBack(const Data &value){

        if (tail == nullptr){
            Node *insNode = new Node(value);
            head = insNode;
            tail = insNode;
        }
        else{
            Node *insNode = new Node(value);
            tail->next = insNode;
            tail = insNode;
        }
        dim = dim + 1;
    }

    template<typename Data>
    void List<Data>::InsertAtBack(Data && dat) {
        if (head == nullptr){
            Node* node = new Node;
            node->dataList = std::move(dat);
            head = node;
            tail = head;
        }
        else{
            Node* node = new Node;
            node->dataList = std::move(dat);
            tail->next = node;
            tail = node;
        }
        dim++;
    }
    template <typename Data>
    bool List<Data>::operator==(const List<Data> &comparisonList) const noexcept{
        if (dim != comparisonList.dim)
            return false;

        Node *temp1 = head;
        Node *temp2 = comparisonList.head;

        while (temp1 != nullptr){
            if (temp1->dataList != temp2->dataList)
                return false;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return true;
    }

    template <typename Data>
    bool List<Data>::operator!=(const List<Data> &comparisonList) const noexcept{
        return !(*this == comparisonList);
    }

    template<typename Data>
    void List<Data>::Print() const{
        
        std::cout<<"Printing list, dim = "<<dim<<std::endl;
        for(unsigned long i = 0; i < dim; i++){
            std::cout<<operator[](i)<<" ";
        }
        std::cout<<std::endl;
    }

    template <typename Data>
    Data &List<Data>::Front() const
    {
        if (dim == 0)
            throw std::length_error("The List is empty");
        else return head->dataList;
    }

    template <typename Data>
    Data &List<Data>::Back() const
    {
        if (dim == 0)
            throw std::length_error("The List is empty");
        else return tail->dataList;
    }

    template <typename Data>
    Data& List<Data>::operator[](ulong index) const
    {
        if (index >= dim || index < 0)
            throw std::out_of_range("Index out of range");
        else
        {
            Node *temp = head;
            while(temp!=nullptr)
            {
                if (index == 0)
                    return temp->dataList;
                else
                {
                    temp = temp->next;
                    index--;
                }
            }
            
            return temp->dataList;
        }
        
    }

    template <typename Data>
    void List<Data>::Clear()
    {
        for (unsigned int i = 0; i < dim; i++)
        {
            RemoveFromFront();
        }
        head = nullptr;
        tail = nullptr;
        dim = 0;
    }

    template <typename Data>
    void List<Data>::MapPreOrder(MapFunctor funct, void *opt)
    {
        MapPreOrder(funct,opt,head);
      
    }

    template <typename Data>
    void List<Data>::Map(MapFunctor funct, void *opt)
    {
        MapPreOrder(funct, opt);
    }

    template <typename Data>
    void List<Data>::MapPostOrder(MapFunctor funct, void *opt)
    {
        MapPostOrder(funct, opt,head);
       
    }

    template <typename Data>
    void List<Data>::FoldPreOrder(FoldFunctor funct, const void *initValue, void *acc) const
    {
        FoldPreOrder(funct, initValue, acc, head);
        
    }
    template <typename Data>
    void List<Data>::FoldPreOrder(FoldFunctor funct, const void *initValue, void *acc,Node* cur) const
    {
        
        for(;cur!=nullptr;cur=cur->next)
        {
            funct(cur->dataList, initValue, acc);
        }
        
        
    }

    template <typename Data>
    void List<Data>::Fold(FoldFunctor funct, const void *initValue, void *acc) const
    {
        FoldPreOrder(funct, initValue, acc);
    }

    template <typename Data>
    void List<Data>::FoldPostOrder(FoldFunctor funct, const void *initValue, void *acc) const
    {
        FoldPostOrder(funct, initValue, acc, head);
        
    }
    template <typename Data>
    void List<Data>::FoldPostOrder(FoldFunctor funct, const void *initValue, void *acc,Node* cur) const
    {
        if(cur!=nullptr)
        {
            
            FoldPostOrder(funct, initValue, acc,cur->next);
            funct(cur->dataList, initValue, acc);
            
        }
        
    }
    
    template <typename Data>
    void List<Data>::MapPreOrder(MapFunctor funct, void *opt, Node* cur)
    {
        if(cur!=nullptr)
        {
            for(;cur!=nullptr;cur=cur->next)
            {
                funct(cur->dataList, opt);
            }
        }
        
    }
    template <typename Data>
    void List<Data>::MapPostOrder(MapFunctor funct, void *opt, Node* cur)
    {
        
        if(cur!=nullptr)
        {
            for(;cur!=nullptr;cur=cur->next)
            {
                MapPostOrder(funct, opt, cur->next);
                funct(cur->dataList, opt);
            }
        }
        
    }
    // ----------------FUNZIONI AUSILIARIE---------------------
    template <typename Data>
    void List<Data>::MapPreOrder(MapFunctor funct, void *opt, unsigned int ind)
    {
        
        if (ind >= dim)
            throw std::length_error("Index out of range");

        Node *temp = head;
        for (unsigned long i = 0; i < ind; i++)
        {
            temp = temp->next;
        }

        while (temp != nullptr)
        {
            funct(temp->dataList, opt);
            temp = temp->next;
        }
    }

    template <typename Data>
    void List<Data>::FoldPreOrder(FoldFunctor funct, const void *initValue, void *acc, unsigned int ind) const
    {
        
        if (ind >= dim)
            throw std::length_error("Index out of range");

        Node *temp = head;
        for (unsigned int i = 0; i < ind; i++)
        {
            temp = temp->next;
        }

        while (temp != nullptr)
        {
            funct(temp->dataList, initValue, acc);
            temp = temp->next;
        }
    }

    template <typename Data>
    void List<Data>::FoldPostOrder(FoldFunctor funct, const void *initValue, void *acc, unsigned int postInd) const
    {
        
        if(dim==0)return;
        if (postInd >= dim)
            throw std::length_error("Index out of range");

        for (unsigned int i = dim - 1; i >= postInd; i--)
        {
            funct(operator[](i), initValue, acc);
        }
    }

    template <typename Data>
    void List<Data>::MapPostOrder(MapFunctor funct, void *opt, unsigned int postInd)
    {
        
        if(dim == 0)return;
        if (postInd >= dim)
            throw std::length_error("Index out of range");

        for (unsigned int i = dim - 1; i >= postInd; i--)
        {
            funct(operator[](i), opt);
        }
    }
}
