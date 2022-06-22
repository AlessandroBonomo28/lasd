
namespace lasd {

/* ************************************************************************** */

template<typename Data>
QueueLst<Data>::QueueLst(const LinearContainer<Data> & copyContainer){
    for(ulong i =0;i<copyContainer.Size();i++){
        List<Data>::InsertAtFront(copyContainer[i]);
    }
}

template<typename Data>
QueueLst<Data>::QueueLst(const QueueLst<Data>& copyQueue) noexcept{
    Node* temp = (Node*)copyQueue.head;
    while(temp!=nullptr){
        List<Data>::InsertAtBack(temp->dataList);
        temp =(Node*) temp->next;
    }
    
}
template<typename Data>
QueueLst<Data>::QueueLst(QueueLst<Data>&& copyQueue) noexcept{
    std::swap(dim,copyQueue.dim);
    std::swap(head,copyQueue.head);
    std::swap(tail,copyQueue.tail);
}

template<typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst& copyQueue) noexcept{
    Clear();
    Node* temp = (Node*)copyQueue.head;
    while(temp!=nullptr){
        List<Data>::InsertAtBack(temp->dataList);
        temp = (Node*)temp->next;
    }
    return *this;
}

template<typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(QueueLst&& copyQueue) noexcept{
    std::swap(dim,copyQueue.dim);
    std::swap(head,copyQueue.head);
    std::swap(tail,copyQueue.tail);
    return *this;
}

template<typename Data>
bool QueueLst<Data>::operator==(const QueueLst& comparisonVector) const noexcept{
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
bool QueueLst<Data>::operator!=(const QueueLst& comparisonVector)const noexcept{
   return !(*this == comparisonVector);
}

template<typename Data>
Data QueueLst<Data>::Head() const{
    if (dim != 0 ){
        return tail->dataList;
    }
    else {
        throw std::length_error("Access to an empty stack. ");
    }
}

template<typename Data>
Data& QueueLst<Data>::Head(){
    if (dim != 0 ){
        return tail->dataList;
    }
    else {
        throw std::length_error("Access to an empty stack. ");
    }
}



template<typename Data>
void QueueLst<Data>::Dequeue(){
    if (dim != 0 ){
        List<Data>::RemoveFromBack();
        
    }
    else {
        throw std::length_error("Access to an empty stack. ");
    }
}

template<typename Data>
Data QueueLst<Data>::HeadNDequeue(){
    if (dim != 0 ){
        Data d = Head();
        Dequeue();
        return d;
    }
    else {
        throw std::length_error("Access to an empty stack. ");
    }
}

template<typename Data>
void QueueLst<Data>::Enqueue(const Data& d) noexcept{
    List<Data>::InsertAtFront(d);
}

template<typename Data>
void QueueLst<Data>::Enqueue(Data&& d) noexcept{
    List<Data>::InsertAtFront(std::move(d));
}

template<typename Data>
void QueueLst<Data>::Clear(){
    List<Data>::Clear();
}
/* ************************************************************************** */

}
