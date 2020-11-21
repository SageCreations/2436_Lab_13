#include <fstream>
#include <iostream>
#include <string>
#include <map>

#include "CSVRow.h"

using namespace std;

struct City {
    string ID ;
    string name;
    string fips;
    int population;

    City(string id, string n, string f, int p) {
        ID = id;  
        name = n;
        fips = f;
        population = p;
    }
};

std::istream& operator>>(std::istream& str, CSVRow& data) {
    data.readNextRow(str);
    return str;
}

int main() {
    string fips;
    int key;
    bool found;

    std::ifstream file("500Cities.csv");

    if (!file.fail()) {
        // declare an STL map that use a pairing of string, City
        // todo add code here

        CSVRow row;
        while (file >> row) {
            // insert city record into map
            // add code here
        }

        // input key ( fips ) to lookup
        cout << "Enter fips id to be searched: ";
        cin >> fips;
        cout << endl;

        // find, retrieve and output city info basedon key ( fips )
        // todo : add code here
        
    }
    return 0;
}
