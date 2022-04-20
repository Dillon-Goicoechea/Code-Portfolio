/* vsarray.cpp
 * implementation of class VSArray methods
 * Dillon Goicoechea
 * 5/10/2021
 */

#include "object.h"
#include "list.h"
#include "vsarray.h"
#include "sstream"

#include <string>
using std::string;
using namespace std;
/* VSArray constructor
 * constructs VSArray, sets capacity and creates fixed delta for increasing size
 *@param is capacity and increase percentage
 * @return noe
 */
VSArray::VSArray(size_t capacity, double increasePercentage): _capacity(capacity),_delta(static_cast<size_t>(capacity*increasePercentage)){
    _data= new Object* [_capacity];
    for(size_t i=0; i<_capacity;i++){
        _data[i]= nullptr;
    }
}
/* VSArray constructor
 * constructs VSArray from another list
 *@param list
 * @return none
 */
VSArray::VSArray(const VSArray& list): _capacity(list._capacity){
    _data= new Object* [_capacity];
    for(size_t i=0; i<_capacity;i++){
        _data[i]= list.Get(i)->Clone();
    }
    for(size_t i=0; i<_capacity;i++){
        _data[i]= nullptr;
    }
}
/* VSArray destructor
 * deallocates VSArray memory
 *@param none
 * @return noe
 */
VSArray::~VSArray(){
   for(size_t i=0; i<_capacity;i++){
      delete _data[i];
    }
   delete[] _data;
}
/* VSArray deep copy
 *@param list
 * @return none
 */
const VSArray& VSArray::operator=(const VSArray& rhs){
    if(this==&rhs){
        return *this;
    }
    if(_capacity!=rhs._capacity){
        Clear();
        delete[] _data;
        _capacity=rhs._capacity;
        _data= new Object* [_capacity];
        for(size_t i=0; i<_capacity;i++){
            _data[i]= nullptr;
        }
    }
    for(size_t i=0; i<_capacity;i++){
        _data[i]= rhs.Get(i)->Clone();
    }
	return *this;
}
/* VSArray insert
 * inserts element at position
 *@param is object and position
 * @return bool
 */
bool VSArray::Insert(Object* element, size_t position){
    if (position > _size){
        return false;
    }
    if((_capacity==position)||(_size==_capacity)){
        Resize();
    }
    for(size_t i=_capacity-1;i>position;i--){
        _data[i]=_data[i-1];
    }
    _data[position]=element;
    ++_size;
    return true;
}
/* VSArray search
 * searches VSArray for element
 *@param is element
 * @returns -1 if not found, index if found
 */
int VSArray::IndexOf(const Object* element)const{
    for(size_t i=0; i<_size;i++){
        if(_data[i]->Equals(*element)){
            return i;
        }
    }
	return -1;
}
/* VSArray remove
 * removes element from VSArray
 *@param position
 * @return removed element
 */
Object* VSArray::Remove(size_t position){
    if(position >_size){
        return nullptr;
    }
    Object* retVal=_data[position];
    for(size_t i=position; i<_size-1;i++){
        _data[i]=_data[i+1];
    }
    _data[_size-1]= nullptr;
    _size--;
    return retVal;
}
/* VSArray get
 * returns element from VSArray
 *@param position
 * @return element at position
 */
Object* VSArray::Get(size_t position)const{
    if(position>_size){
        return nullptr;
    }
	return _data[position];
}
/*  VSArray to string
 * coverts  VSArray to string format
 * @param is none
 * @return is string
 */
string VSArray::ToString()const{
    stringstream retVal;
    retVal <<"{";
    for(size_t i=0; i<_size;i++){
        if((i=_size-1)){
            retVal << _data[i] <<"}";
        }
        else {
            retVal << _data[i] << ", ";
        }
    }
	return retVal.str();
}
/* VSArray clear
 * Clears VSArray
 * @param is none
 * @return none
 */
void VSArray::Clear(){

    delete[] _data;
    _size=0;
}
/*VSArray resize
 * increases size of VSArray with fixed delta
 * @param none
 * @return none
 */
void VSArray::Resize() {
    size_t newCapacity=_capacity+_delta;
    Object **temp = new Object *[newCapacity];
    for (size_t i = 0; i < _capacity; i++) {
        temp[i] = _data[i];
    }

    size_t save=_size;
    Clear();
    _size=save;

    _capacity = _capacity + _delta;
    _data = new Object *[_capacity];
    for (size_t i = 0; i < _capacity; i++) {
       _data[i] = nullptr;
    }
    for (size_t i = 0; i < _capacity-_delta; i++) {
        _data[i] = temp[i];
    }
    delete[] temp;

}
/*VSArray get capacity
 * returns capacity of VSArray
 * @param none
 * @return none;
 */
    size_t VSArray::GetCapacity() const {
        return _capacity;
    }
