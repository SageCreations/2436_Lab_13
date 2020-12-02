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
    
    City() {
        ID = "";
        name = "";
        fips = "";
        population = 0;
    }
    
    City(string id, string n, string f, int p) {
        ID = id;  
        name = n;
        fips = f;
        population = p;
    }
};

std::ostream& operator<<(std::ostream& os, const City& a) {
  os << "stateid: " << a.ID << " // city: " << a.name
     << " // fips: " << a.fips << " // population: " << a.population
     << std::endl;
  return os;
}

int main() {
    string fips;
    int key;
    bool found;

    std::ifstream file("500Cities.csv");

    if (!file.fail()) {
        // declare an STL map that use a pairing of string, City
        City places[500];
        map<string, City> cities;

        CSVRow row;
        int index = 0;
        while (file >> row) {
            // insert city record into map
            places[index] = City(row[0], row[1], row[2], stoi(row[3]));
            cities.insert( pair<string, City>(row[2], places[index]) );
            index++;
        }

        //https://www.geeksforgeeks.org/map-insert-in-c-stl/
        //date found: 12/2/2020
        // used this to see how it was being/if stored.
        // also made it easier to test the look up.
        cout << "KEY\tELEMENT\n";
        for (auto itr = cities.begin(); itr != cities.end(); ++itr) {
            cout << itr->first << "\t" << itr->second << "\n";
        }

        // input key ( fips ) to lookup
        cout << "Enter fips id to be searched: ";
        cin >> fips;
        cout << endl;

        // find, retrieve and output city info based on key ( fips )
        auto theOne = cities.find(fips);
        if(theOne == cities.end()) {
            cout << "The fips id was not found!!!" << endl; 
        } else {
            cout << "The City has been found : " 
                 << theOne->first << " // " << theOne->second ; 
        }
    }
        
    return 0;
}
