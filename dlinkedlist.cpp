/* dlinkedlist.cpp
 * implementation of class DoubleLinkedList methods
 * Dillon Goicoechea
 * 5/10/2021
 */

#include "object.h"
#include "dlinkedlist.h"
#include "sstream"
using namespace std;

#include <string>
using std::string;

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList &other): _head(nullptr), _tail(nullptr){

}

DoubleLinkedList &DoubleLinkedList::operator=(const DoubleLinkedList &rhs) {
    if(this==&rhs){
        return *this;
    }

	return *this;
}
/* Double Linked list constructor
 * Constructs DoubleLinkedList
 * @param is none
 * @return none
 */
DoubleLinkedList::DoubleLinkedList(): _head(nullptr), _tail(nullptr){

}
/* Double linked list destructor
 * deallocates memory
 * @param none
 * @return none
 */
DoubleLinkedList::~DoubleLinkedList() {

    while(_head->next!= nullptr){
        Node* temp=_head->next;
        _head->next=temp->next;
        delete temp;
    }

}
/* Double Linked list insert
 * inserts node into DoubleLinkedList
 * @param is object pointer and position
 * @return is boolean
 */
bool DoubleLinkedList::Insert(Object *element, size_t position) {
    if(position > _size){
        return false;
    }
    Node* newNode= new Node;
    newNode->data=element;
    newNode->next= nullptr;
    newNode->previous= nullptr;
    if(_size==0){
        _head=newNode;
        _tail=newNode;
    }
    else if(position==0){
        newNode->next=_head;
        _head->previous=newNode;
        _head=newNode;
    }
    else if (position==_size){
        _tail->next=newNode;
         newNode->previous=_tail;
        _tail=newNode;
    }
    else {
        Node *temp1 = _head;
        Node *temp2 = nullptr;
        for(size_t i=0;i<=_size;++i){
            if (i==position){
                newNode->next=temp1;
                newNode->previous=temp2;
                temp2->next=newNode;
                temp1->previous=newNode;
                break;
            }
            temp2=temp1;
            temp1=temp1->next;
        }
    }
    ++_size;
    return true;

}
/* Double Linked list search
 * searches linked list for object DoubleLinkedList
 * @param is object
 * @return -1 if not found, index if found
 */
int DoubleLinkedList::IndexOf(const Object *element) const {
	if(_head==nullptr){
	    return -1;
	}
    Node* temp=_head;
    size_t result=0;
    if(_size==1) {
        if (_head->data->Equals(*element)) {
            return 0;
        }
        return -1;
    }
        for(temp=_head;temp!= nullptr;temp=temp->next){
            if (temp->data->Equals(*element)){
           return result;
       }
            result++;
	}
return-1;
}
/* Double Linked list remove
 * removes node from DoubleLinkedList
 * @param is position
 * @return is object of removed node
 */
Object *DoubleLinkedList::Remove(size_t position) {
	if(position>_size){
	    return nullptr;
	}
	Object* retVal= nullptr;
	Node* temp= nullptr;
	Node* temp2= nullptr;
	Node* toRemove= nullptr;
	if(position==0 && _size==1){
	    delete _head;
	}
	else if(position==0){
	    retVal=_head->data;
        temp=_head->next;
        temp->previous= nullptr;
	    _head->data= nullptr;
        _head->next= nullptr;
        delete _head;
        _head=temp;
	}
	else if(position==_size-1){
	    temp=_tail;
	    _tail=temp->previous;
	    _tail->next= nullptr;
	    temp->previous= nullptr;
	    retVal=temp->data;
	    delete temp;
	}

	else{
	    temp=_head;
        for(size_t i=0;i<=_size;++i){
            if(i==position){
                toRemove=temp;
                temp=toRemove->previous;
                temp2=toRemove->next;
                temp->next=temp2;
                temp2->previous=temp;
                retVal=toRemove->data;
                delete toRemove;
                break;
            }
	        temp=temp->next;
	    }
	}
	_size--;
	return retVal;
}
/* Double Linked list get
 * gets object of element of the DoubleLinkedList
 * @param is position
 * @return is object
 */
Object *DoubleLinkedList::Get(size_t position) const {
    if(position>_size){
        return nullptr;
    }
    Node* temp=_head;
    for(size_t i=0;i<position;++i){
        temp=temp->next;
    }
    return temp->data;
}
/* Double Linked list to string
 * coverts DoubleLinkedList to string format
 * @param is none
 * @return is string
 */
string DoubleLinkedList::ToString() const {
    stringstream retVal;
    retVal << "{";
    Node* temp=_head;
    if(_head==_tail){
        retVal << temp->data->ToString() << "}";
        return retVal.str();
    }
    for(size_t i=0;i<_size-1;++i){
        retVal << temp->data->ToString() << ", ";
    }
    temp=temp->next;
    retVal<< temp->data->ToString() << "}";
	return retVal.str();
}
/* Double Linked list clear
 * Clears DoubleLinkedList
 * @param is none
 * @return none
 */
void DoubleLinkedList::Clear() {
    while(_size!=0){
        Object* temp= Remove(0);
        delete temp;
    }
    _size=0;
}
