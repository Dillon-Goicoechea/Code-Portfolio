/*
 * Title:		professor.cpp
 * Purpose:		implementation of class Professor methods
 * Author:		Dillon Goicoechea
 * Date:		04 28,2021
 */

#include "date.h"
#include "person.h"
#include "professor.h"
#include "sstream"
#include "string"
/*Professor Constructor
 * Creates Professor object
 * @param is String name, Date birthday, and string department
 * @return none
 */
Professor::Professor(const string& name,const Date& birthday,const string& department) : Person(name, birthday), _department(department),_hireDate(Now()), _rank(ASSISTANT_PROFESSOR), _salary(60000) {

}

/*Professor Constructor
 * Creates Professor object
 * @param is String name, Date birthday, string department, Date hireDate
 * @return none
 */
Professor::Professor(const string& name,const Date& birthday,const string& department,const Date& hireDate) : Person(name, birthday), _department(department), _hireDate(hireDate), _rank(ASSISTANT_PROFESSOR), _salary(60000) {

}

/*Professor Constructor
 * Creates Professor object
 * @param is String name, Date birthday, string department, Date hireDate, Rank rank, and float salary
 * @return none
 */
Professor::Professor(const string& name,const Date& birthday,const string& department,const Date& hireDate,Rank rank,float salary) : Person(name, birthday),_department(department), _hireDate(hireDate),
_rank(rank),_salary(salary) {

}

/*Professor destructor
 * destructs Professor object
 * @param none
 * @return none
 */
Professor::~Professor() {

}

/* Professor Read
 * Reads Professor data from file
 * UNFINISHED
 * @param istream
 * @return none
 */
void Professor::Read(istream&) {

}

/*Professor Write
* Writes professor object data to file
* UNFINISHED
* @param ostream
* @return none
*/
void Professor::Write(ostream& output)  const {
    output << "R " << _name << " " << _birthDay.GetYear() << " " << _birthDay.GetMonth() << " " << _birthDay.GetDay() << " " << _department << " " << _hireDate.GetYear() <<" ";
    output << _hireDate.GetMonth() <<" " << _hireDate.GetDay() << " " << _salary << endl;
}

/* Professor Get Salary
 * returns Professor object salary
 * @param none
 * @return _salary
 */
float Professor::GetSalary() const{
    return _salary;
}

/*Professor Raise
 * Raises professor salary
 * multiples salary by 1+(percentage/100)
 * @param float percentage
 * @return none
 */
void Professor::Raise(float percentage) {
_salary*=(1+(percentage/100));
}

/*Professor Promote
 * promotes professor
 * @param none
 * @return none
 */
void Professor::Promote() {
if(_rank!= PROFESSOR){
    if (_rank==ASSISTANT_PROFESSOR){
        _rank=ASSOCIATE_PROFESSOR;
    }
    else{
        _rank=PROFESSOR;
    }
}
}

/* Professor To String
 * Puts Professor info into stringstream variable then returns stringstream to string function
 * @param none
 * @return string of professor object data
 */
string Professor::ToString() {
    stringstream ss;
    ss<< "{Person: {name: " << _name << ", birthday: " << _birthDay.ToString() << "}, department: " << _department << ", rank: " << _rank << ", hire date: " << _hireDate.ToString() <<", salary: " << _salary << "}";
    return ss.str();
}

/*Professor Get Rank
 * Returns Professor rank
 * @param none
 * @return noe
 */
Rank Professor::GetRank() const{
    return _rank;
}
