//
// Created by dgoic on 3/9/2021.
//


#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "ReadCSV.h"

/*The read file is a loop so enter after each getline pushback for the temp string so it adds it to each vector*/
// File is an adapted version of ReadCSV.ccp provided by Professor Cameron

int ReadFile::ReadCSVFile() {
    std::string header;
    std::vector<std::string> lines;
    int rows;
    int currRow=1;
    std::stringstream
            lineStream(header); // used to read the field (column/cell) data from the data line (row) string
    std::string col01, col02, col03, col04, col05, col06, col07, col08, col09, col10, col11, col12, col13, col14, col15, col16, col17, col18, col19, col20, col21, col22, col23, col24, col25;
    std::string id, prefix, first, mi, last, gender, email, fatherName, motherName, motherMaiden, dob, age, weightKg, join, salary, payHike, SSN, phone, placeName, county, city, state, zip, region, user;    // WARNING: This might not be the exactly match the field names and sequence ofthe data in your file.
    rows = ReadCSV(newFileName, header, lines);  // put the file data.csv in the same directory as main.cpp
    std::cout << rows << " data rows found." << std::endl << std::endl;

    for (auto l : lines) {   // process the table data that was read (all the rows)
        std::stringstream lineStream(l); // prepare to parse a line (row) of data using stringStream
        noskipws(
                lineStream);     // this is supposed to cause getline to ignore whitespace, but...                                     // it's not working, so all spaces have been converted to underscores in the data
        //reads the string from the file using getlines
        getline(lineStream, id, ',');
        getline(lineStream, prefix, ',');
        getline(lineStream, first, ',');
        getline(lineStream, mi, ',');
        getline(lineStream, last, ',');
        getline(lineStream, gender, ',');
        getline(lineStream, email, ',');
        getline(lineStream, fatherName, ',');
        getline(lineStream, motherName, ',');
        getline(lineStream, motherMaiden, ',');
        getline(lineStream, dob, ',');
        getline(lineStream, age, ',');
        getline(lineStream, weightKg, ',');
        getline(lineStream, join, ',');
        getline(lineStream, salary, ',');
        getline(lineStream, payHike, ',');
        getline(lineStream, SSN, ',');
        getline(lineStream, phone, ',');
        getline(lineStream, placeName, ',');
        getline(lineStream, county, ',');
        getline(lineStream, city, ',');
        getline(lineStream, state, ',');
        getline(lineStream, zip, ',');
        getline(lineStream, region, ',');
        getline(lineStream, user, ',');


        //Checks if any incomplete data was read, If read then it records occurrence number, position, and breaks loop before saved to vectors
        if((id=="")||(prefix=="")||(first=="")||(mi=="")||(last=="")||(gender=="")||(email=="")||(fatherName=="")||(motherName=="")
        ||(motherMaiden=="")||(dob=="")||(age=="")||(weightKg=="")||(join=="")||(salary=="")||(payHike=="")||(SSN=="")||(phone=="")
        ||(placeName=="")||(county=="")||(city=="")||(state=="")||(zip=="")||(region=="")||(user=="")){
            ++numRowsIncomplete;
            missingDataRows.push_back(currRow);
            ++currRow;
            continue;
        }


        // parse each column of data (up to the next comma)
        getline(lineStream, col01, ',');
        getline(lineStream, col02, ',');
        getline(lineStream, col03, ',');
        getline(lineStream, col04, ',');
        getline(lineStream, col05, ',');
        getline(lineStream, col06, ',');
        getline(lineStream, col07, ',');
        getline(lineStream, col08, ',');
        getline(lineStream, col09, ',');
        getline(lineStream, col10, ',');
        getline(lineStream, col11, ',');
        getline(lineStream, col12, ',');
        getline(lineStream, col13, ',');
        getline(lineStream, col14, ',');
        getline(lineStream, col15, ',');
        getline(lineStream, col16, ',');
        getline(lineStream, col17, ',');
        getline(lineStream, col18, ',');
        getline(lineStream, col19, ',');
        getline(lineStream, col20, ',');
        getline(lineStream, col21, ',');
        getline(lineStream, col22, ',');
        getline(lineStream, col23, ',');
        getline(lineStream, col24, ',');
        getline(lineStream, col25, ',');



        //reads values into protected containers
        idVec.push_back(id);
        namePrefixVec.push_back(prefix);
        firstNameVec.push_back(first);
        midInitialVec.push_back(mi);
        lastNameVec.push_back(last);
        genderVec.push_back(gender);
        emailAddressVec.push_back(email);
        fatherNameVec.push_back(fatherName);
        motherNameVec.push_back(motherName);
        motherMaidenVec.push_back(motherMaiden);
        dateOfBirthVec.push_back(dob);
        ageVec.push_back(age);
        weightInKilosVec.push_back(weightKg);
        dateOfJoinVec.push_back(join);

        //transfers salary string into a int vector via switching from string to int via sstream.
        std::stringstream geek(salary);
        int sal = 0;
        geek >> sal;
        salaryVec.push_back(sal);

        //reads values into protected containers
        lastPayHikeVec.push_back(payHike);
        SSNVec.push_back(SSN);
        phoneNumVec.push_back(phone);
        placeNameVec.push_back(placeName);
        countyVec.push_back(county);
        cityVec.push_back(city);
        stateVec.push_back(state);
        zipCodeVec.push_back(zip);
        regionVec.push_back(region);
        userNameVec.push_back(user);
        ++currRow;
    }
    for (int i = 0; i < idVec.size(); ++i) { //this loop checks for duplicate Id nums and deletes if found.
        for (int j = i+1; j < idVec.size(); ++j) {
            if (idVec.at(i)==idVec.at(j)){
                duplicateRows.push_back((j+1));//records duplicate Id row
                idVec.erase(idVec.begin()+j);
                //this block deletes the elements of duplicate data from vectors for data purity
                namePrefixVec.erase(namePrefixVec.begin()+j);
                firstNameVec.erase(firstNameVec.begin()+j);
                midInitialVec.erase(midInitialVec.begin()+j);
                lastNameVec.erase(lastNameVec.begin()+j);
                genderVec.erase(genderVec.begin()+j);
                emailAddressVec.erase(emailAddressVec.begin()+j);
                fatherNameVec.erase(fatherNameVec.begin()+j);
                motherNameVec.erase(motherNameVec.begin()+j);
                motherMaidenVec.erase(motherMaidenVec.begin()+j);
                dateOfBirthVec.erase(dateOfBirthVec.begin()+j);
                ageVec.erase(ageVec.begin()+j);
                weightInKilosVec.erase(weightInKilosVec.begin()+j);
                dateOfJoinVec.erase(dateOfJoinVec.begin()+j);
                salaryVec.erase(salaryVec.begin()+j);
                lastPayHikeVec.erase(lastPayHikeVec.begin()+j);
                SSNVec.erase(SSNVec.begin()+j);
                phoneNumVec.erase(phoneNumVec.begin()+j);
                placeNameVec.erase(placeNameVec.begin()+j);
                countyVec.erase(countyVec.begin()+j);
                cityVec.erase(cityVec.begin()+j);
                stateVec.erase(stateVec.begin()+j);
                zipCodeVec.erase(zipCodeVec.begin()+j);
                regionVec.erase(regionVec.begin()+j);
                userNameVec.erase(userNameVec.begin()+j);
                ++numDuplicateRows;
            }
        }
    }

   std::cout << "File read completed" << std::endl;
    numRows=rows;
    return rows; //used in test one assert
} //used to read data from the CSV files provided by user, modified version of file by Prof. Cameron

int ReadFile::ReadCSV(std::string filename, std::string &header, std::vector <std::string> &records) {
    std::ifstream inFS;       // input file stream
    std::string record;       // one complete input line (row)
    int rows = 0; // row count does not include header row
    inFS.open(filename);
    std::cout << "Reading: " << filename << std::endl;
    if (!inFS.is_open()) { // check for successful open
        std::cout << "Could not open file." << std::endl;
        return -1;   // return error
    }

    getline(inFS, header); // read the header
    while (!inFS.eof()) {         // read all the rows
        inFS >> record;
        if (!inFS.fail()) {
            records.push_back(record); // store the input (complete line)
            rows++;                    // count the number of rows
        }
    }
    // close file when done reading
    inFS.close();
    numRows=rows;
    return rows;
} // function is used to access and close CSV, written by Prof. Cameron

