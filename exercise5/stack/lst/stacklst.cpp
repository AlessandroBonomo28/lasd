
namespace lasd {

/* ************************************************************************** */

template<typename Data>
StackLst<Data>::StackLst(const LinearContainer<Data> & copyContainer){
    for(ulong i =0;i<copyContainer.Size();i++){
        List<Data>::InsertAtBack(copyContainer[i]);
    }
}

template<typename Data>
StackLst<Data>::StackLst(const StackLst<Data>& copyStack) noexcept{
    Node* temp = (Node*)copyStack.head;
    while(temp!=nullptr){
        List<Data>::InsertAtBack(temp->dataList);
        temp =(Node*) temp->next;
    }
    
}
template<typename Data>
StackLst<Data>::StackLst(StackLst<Data>&& copyStack) noexcept{
    std::swap(dim,copyStack.dim);
    std::swap(head,copyStack.head);
    std::swap(tail,copyStack.tail);
}

template<typename Data>
StackLst<Data>& StackLst<Data>::operator=(const StackLst& copyStack) noexcept{
    Clear();
    Node* temp = (Node*)copyStack.head;
    while(temp!=nullptr){
        List<Data>::InsertAtBack(temp->dataList);
        temp = (Node*)temp->next;
    }
    return *this;
}

template<typename Data>
StackLst<Data>& StackLst<Data>::operator=(StackLst&& copyStack) noexcept{
    std::swap(dim,copyStack.dim);
    std::swap(head,copyStack.head);
    std::swap(tail,copyStack.tail);
    return *this;
}

template<typename Data>
bool StackLst<Data>::operator==(const StackLst& comparisonVector) const noexcept{
    if(dim!=comparisonVector.Size()){
        return false;
    }
    Node* temp1 = (Node*)comparisonVector.head;
    Node* temp2 = (Node*)head;
    if(temp1==nullptr && temp2==nullptr){
        return true;
    }
    while(temp1!=nullptr){
        if(temp1->dataList!=temp2->dataList){
            return false;
        }
        temp1 = (Node*)temp1->next;
        temp2 = (Node*)temp2->next;
    }

    return true;
}

template<typename Data>
bool StackLst<Data>::operator!=(const StackLst& comparisonVector)const noexcept{
   return !(*this == comparisonVector);
}

template<typename Data>
Data StackLst<Data>::Top() const{
    if (dim != 0 ){
        return head->dataList;
    }
    else {
        throw std::length_error("Access to an empty stack. ");
    }
}

template<typename Data>
Data& StackLst<Data>::Top(){
    if (dim != 0 ){
        return head->dataList;
    }
    else {
        throw std::length_error("Access to an empty stack. ");
    }
}



template<typename Data>
void StackLst<Data>::Pop(){
    if (dim != 0 ){
        List<Data>::RemoveFromFront();
        
    }
    else {
        throw std::length_error("Access to an empty stack. ");
    }
}

template<typename Data>
Data StackLst<Data>::TopNPop(){
    if (dim != 0 ){
        Data d = Top();
        Pop();
        return d;
    }
    else {
        throw std::length_error("Access to an empty stack. ");
    }
}

template<typename Data>
void StackLst<Data>::Push(const Data& d) noexcept{
    List<Data>::InsertAtFront(d);
}

template<typename Data>
void StackLst<Data>::Push(Data&& d) noexcept{
    List<Data>::InsertAtFront(std::move(d));
}

template<typename Data>
void StackLst<Data>::Clear(){
    List<Data>::Clear();
}
/* ************************************************************************** */

}
