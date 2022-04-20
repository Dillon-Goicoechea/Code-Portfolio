//
// Created by dgoic on 3/9/2021.
//


#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <assert.h>
#include "EmployeeData.h"
using namespace std;


void EmployeeData::InputFileName(std::string fileName) {
    newFileName=fileName; // saves user input into filename variable used in Read CSV functions
} // used to save new file name for reading files other than test and data_v1


void EmployeeData::PhoneNumList() {

// title and header block for report
std::cout << " Employee Phone Number List: " << std::endl;
    cout << left;
std::cout << std::setw(8) << "ID" << std::setw(17) << "| Last Name" ;
std::cout << std::setw(15) << "| First Name" << std::setw(15) << "| Phone Number" << std::endl;

for(int i=0; i<idVec.size();++i){ // for loop that outputs the data into columns
    cout << left;
    std::cout << std::setw(8) << idVec.at(i) << std::setw(17) <<  lastNameVec.at(i);
    std::cout  << std::setw(15) << firstNameVec.at(i) << std::setw(10) << phoneNumVec.at(i) << std::endl;

}




}  // Outputs Employee name, ID, and Phone number

 void EmployeeData::DataQualityReport() {
    //title and header block for data
std::cout << " Input Data Quality Report:" << std::endl;
std::cout<<std::endl;
     cout << left;
cout  << std::setw(6) << "Emp ID" << setw(5)<< "| Prefix"<<setw(15)<< "| First Name"<< std::setw(16) << "| Middle Initial";
cout << std::setw(15) << "| Last Name" << setw(10) << "| Gender" << setw(31) << "| Email Address" << setw(25) << "| Father Name";
cout << setw(25) << "| Mother Name" << setw(25) << "| Mother Maiden" << setw(15) << "| Date of Birth";
cout << setw(5) << "| Age" << setw(15) << "| Weight in Kgs" << setw(17) << "| Date of Joining" << setw(8) << "| Salary";
cout << setw(13) << "| Last % Hike" << setw(12) << "| SSN" << setw(15) << "| Phone Number" << setw(25) << "| Place Name";
cout << setw(15) << "| County" << setw(25) << "| City" << setw(20) << "| State" << setw(10) << "| Zip Code";
cout << setw(10) << "| Region" << setw(17) << "| User Name" << endl;

     for (int i = 0; i < idVec.size(); ++i) { // for loop that outputs data into columns
         cout << left;
         cout  << std::setw(8) << idVec.at(i) << setw(5)<< namePrefixVec.at(i)<<setw(15)<< firstNameVec.at(i)<< std::setw(16) << midInitialVec.at(i);
         cout << std::setw(15) << lastNameVec.at(i) << setw(10) << genderVec.at(i) << setw(31) << emailAddressVec.at(i) << setw(25) << fatherNameVec.at(i);
         cout << setw(25) << motherNameVec.at(i) << setw(25) << motherMaidenVec.at(i) << setw(15) << dateOfBirthVec.at(i);
         cout << setw(5) << ageVec.at(i) << setw(15) << weightInKilosVec.at(i) << setw(17) << dateOfJoinVec.at(i)<< setw(8) << salaryVec.at(i);
         cout << setw(13) << lastPayHikeVec.at(i) << setw(12) << SSNVec.at(i) << setw(15) << phoneNumVec.at(i) << setw(25) << placeNameVec.at(i);
         cout << setw(15) << countyVec.at(i) << setw(25) << cityVec.at(i) << setw(20) << stateVec.at(i) << setw(10) << zipCodeVec.at(i);
         cout << setw(10) << regionVec.at(i) << setw(17) << userNameVec.at(i) << endl;
     }
     cout<<endl;
     //new header for subsection
     cout << "Data Quality Exceptions: " << endl;
     cout << endl;
     cout << " Duplicates: " << endl;
     cout << " Duplicates found on rows:" << endl;
     for (int i = 0; i < duplicateRows.size(); ++i) { // outputs rows duplicates found on
         cout << "  Row " << duplicateRows.at(i) << endl;
     }
     cout << " Total Count of Duplicate Records: " << numDuplicateRows << endl;
     cout << endl;
     cout << " Incomplete Records: " << endl;
     cout << " Incomplete Records found on rows:" << endl;
     for (int i = 0; i < missingDataRows.size(); ++i) { //outputs rows with missing data
         cout << "  Row " << missingDataRows.at(i) << endl;
     }
     cout << " Total Count of Incomplete Records: " << numRowsIncomplete << endl;
     cout << endl;
     cout << " Exceptions Section Summary:" << endl;
     cout << "  Total Error Count: " << numRowsIncomplete+numDuplicateRows << endl;
     cout << "  Total Good Records Count: " << numRows-(numRowsIncomplete+numDuplicateRows) << endl;
 } // Outputs Data quality information regarding duplicate and incomplete data rows

void EmployeeData::CustomReport() {
//title and header block
std::cout << " Employee Contact Information Report: " << std::endl;
cout << left;
std::cout  << std::setw(5) << "Name Prefix" <<std::setw(15)<<"| First Name"<< std::setw(16) << "| Middle Initial";
std::cout  <<std::setw(15) << "| Last Name" << std::setw(25) << "| Email Address" << std::setw(15) << "| Phone Number" << std::endl;

for(int i=0; i<namePrefixVec.size();++i){ // outputs data into columns
    cout << left;
    std::cout << std::setw(5) << namePrefixVec.at(i) <<std::setw(15)<<firstNameVec.at(i)<< std::setw(16) << midInitialVec.at(i);
    std::cout  << std::setw(15)<< lastNameVec.at(i) << std::setw(31) <<"  "<< emailAddressVec.at(i) << std::setw(15) << phoneNumVec.at(i) << std::endl;




}










} // Outputs Employee Name, Prefix, Email, and Phone number

void EmployeeData::EmployeeClusterReport() {
std::vector<std::string> tempZipCode;
std::vector<std::string> tempCity;    //vectors used for storing on repeat versions of main storage vectors
std::vector<std::string> tempState;
int employeeCounter=0;

//title and header block
std:: cout << " Employee Cluster Report: " << std::endl;
    cout << left;
std::cout << std::setw(10) << "Zipcode" << std::setw(25) << "| City" << std::setw(20) << "| State" << std::setw(8) << "| Number of Employees" << std::endl;

for(int i=0;i<zipCodeVec.size();i++){ // loops used for reading one of each zipcode with associated data into tempZipCode vector
    if (tempZipCode.size()==0){
        tempZipCode.push_back(zipCodeVec.at(i));
        tempCity.push_back(cityVec.at(i));
        tempState.push_back(stateVec.at(i));
        continue;
    }
    for (int j = 0; j < tempZipCode.size(); j++) {
        if(tempZipCode.at(j)==zipCodeVec.at(i)){
            break;
        }
        if (j+1==tempZipCode.size()){
            tempZipCode.push_back(zipCodeVec.at(i));
            tempCity.push_back(cityVec.at(i));
            tempState.push_back(stateVec.at(i));
        }
    }



}
    for(int i=0; i < tempZipCode.size();++i){ //outputs data into columns
        employeeCounter=0;
        for(int j=0; j< zipCodeVec.size();++j) {
        if(tempZipCode.at(i)==zipCodeVec.at(j)){
            ++employeeCounter;
        }
        }
        cout << left;

        std::cout  << std::setw(10) <<  tempZipCode.at(i) << std::setw(25) <<  tempCity.at(i);
        std::cout  << std::setw(20) << tempState.at(i) << std::setw(8) << employeeCounter << std::endl;

        }

} // Outputs Zipcode, state, city, and Number of employees there

void EmployeeData::EmployeePayRaiseReport() {
double newSal;
double salDifference;
//title and header block
std::cout << " Employee Pay Raise Report: " << std::endl;
    cout << left;
std:: cout  <<std::setw(23) << "Employee Name"<< std::setw(8) << "| Salary";
std::cout  <<std::setw(9) << "| New Salary" << std::setw(5) << "| Raise Amount" << std::endl;
for(int i=0;i<salaryVec.size();++i){ // outputs data into columns
    newSal= salaryVec.at(i)*1.025;
    salDifference= newSal-salaryVec.at(i); // calculates raise amount via subtracting salary from newSal
    cout << left;
    std ::cout << setw(10)<< firstNameVec.at(i) <<setw(13)<< lastNameVec.at(i);
    std:: cout <<std::setw(8) << salaryVec.at(i) << std::setw(9) << newSal << std::setw(5) << salDifference << std::endl;

}
} // Outputs Employee name, current salary, salary with 2.5% raise, and the difference between both salaries

double EmployeeData::RegionalRaiseReport() {
    std::vector<std::string> tempZipCode; //used to store one of each zipcode
    double testCheck; //used in test two
    //title and header block
    std::cout << "Regional Raise Report: " << std::endl;
    cout << left;
    std::cout << std::setw(12) << "Zip Code" << std::setw(9) << "| Total Raises" << std::endl;
    for(int i=0;i<zipCodeVec.size();i++) { // loops used for reading one of each zipcode with associated data into tempZipCode vector
        if (tempZipCode.size() == 0) {
            tempZipCode.push_back(zipCodeVec.at(i));
            continue;
        }
        for (int j = 0; j < tempZipCode.size(); j++) {
            if (tempZipCode.at(j) == zipCodeVec.at(i)) {
                break;
            }
            if (j + 1 == tempZipCode.size()) {
                tempZipCode.push_back(zipCodeVec.at(i));
            }
        }
    }
    for(int i=0;i<tempZipCode.size();++i){ // outputs data into columns
        double totalRaises=0; //resets for each new zipcode
        cout << left;
        std::cout <<  std::setw(12) << tempZipCode.at(i);
        for(int j=0; j<zipCodeVec.size();++j){
            if(tempZipCode.at(i)==zipCodeVec.at(j)){
                totalRaises+=((salaryVec.at(j)*1.025)-salaryVec.at(j));

            }
        }
        testCheck=totalRaises;//used in test two
        std::cout <<  std::setw(9)<< totalRaises << std::endl;
    }
    return testCheck;//used in test two
} // Outputs Zipcode and total amount of raises in zipcode if all salaries were increased by 2.5%

void EmployeeData::AllReports() {
    PhoneNumList();
    CustomReport();
    DataQualityReport();
    EmployeeClusterReport();
    EmployeePayRaiseReport();
    RegionalRaiseReport();
}  // Calls all report functions

void EmployeeData::TestOne(int rowsActual) {
    // tests read csv row count by assert testing data rows read from test01.csv
    std::cout << " Testing Started:" << std::endl;
    assert(numRows==rowsActual);
    std::cout << " Testing Completed" << std::endl;
}  // Tests rows counted return of ReadCSV using test01.csv file

void EmployeeData::TestTwo() {
    // tests regional raise report return using an assert that checks difference as it is two double/float numbers being compared
    std::cout << " Testing Started:" << std::endl;
   assert((RegionalRaiseReport()-27610.9)<0.00001);
    std::cout << " Testing Completed" << std::endl;
} // Tests regional raises output with test01.csv data



void EmployeeData::AllReportsAndTests() {
    AllReports();
} //Calls all report functions for all reports and tests

void EmployeeData::ClearVectors() {
    // clears all data storage vectors using clear() function
    idVec.clear();
    namePrefixVec.clear();
    firstNameVec.clear();
    midInitialVec.clear();
    lastNameVec.clear();
    genderVec.clear();
    emailAddressVec.clear();
    fatherNameVec.clear();
    motherNameVec.clear();
    motherMaidenVec.clear();
    dateOfBirthVec.clear();
    ageVec.clear();
    weightInKilosVec.clear();
    dateOfJoinVec.clear();
    salaryVec.clear();
    lastPayHikeVec.clear();
    SSNVec.clear();
    phoneNumVec.clear();
    placeNameVec.clear();
    countyVec.clear();
    cityVec.clear();
    stateVec.clear();
    zipCodeVec.clear();
    regionVec.clear();
    userNameVec.clear();
    missingDataRows.clear();
    duplicateRows.clear();
} //used to clear out vectors when saving new data from diff CSV file from current use one


