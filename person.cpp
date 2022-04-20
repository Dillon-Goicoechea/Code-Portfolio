/*
 * Title:		person.cpp
 * Purpose:		implementation of class person methods
 * Author:		Dillon Goicoechea
 * Date:		04 28,2021
 */
#include "person.h"
#include "date.h"
#include "string"
#include "sstream"
#include "fstream"
#include <cstdlib>
using namespace std;
/* Person Constructor
 * creates person object
 * @param is string for _name and date for _birthday
 * @return none
 */
Person::Person(string name, Date birthday) : _name(name), _birthDay(birthday) {

}

/* Person Constructor
 * creates person object
 * @param is string for _name and size_t year, month, date to call date constructor to create date object for _birthday
 * @return none
 */
Person::Person(string name, size_t year, size_t month, size_t day) : _name(name), _birthDay(Date(year,month,day)) {

}

/*Person Destructor
 *destructs person obect
 * @param none
 * @return none
 */
Person::~Person() {

}

/* Person To String
 * Puts Person info into stringstream variable then returns stringstream to string function
 * @param none
 * @return string of person object data
 */
string Person::ToString() const {
    stringstream ss;
    ss<<"{name: "<< _name <<", birthday:"<< _birthDay.ToString() << "}";
    return ss.str();
}

/* Person Read
 * Reads Person data from file
 * UNFINISHED
 * @param istream
 * @return none
 */
void Person::Read(istream& input) {


}

/*Person Write
 * Writes person object data to file
 * UNFINISHED
 * @param ostream
 * @return none
 */
void Person::Write(ostream& output) const {

output << "P " << _name << " " << _birthDay.GetYear() << " " << _birthDay.GetMonth() << " " << _birthDay.GetDay() << endl;

}

/*Person get name
 * Returns person object name
 * @param none
 * @return _name
 */
string Person::GetName() const{
    return _name;
}

/* Person get Age
 * Returns person age
 * divides difference between birthday and now by 365
 * @param none
 * @return age
 */
size_t Person::GetAge() const{
    size_t retVal;
    retVal= (Now().Difference(_birthDay))/365;
    return retVal;
}
