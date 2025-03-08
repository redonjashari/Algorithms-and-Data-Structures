/*
CH-231-A
hw2
Redon Jashari
RJASHARI@constructor.university
*/

#include <iostream>
#include <map>
#include <fstream>
#include <string>

using namespace std;

int main() {
    map<string, string> bdayMap;

    ifstream dataFile("data.txt");
    if (!dataFile)
    {
        cerr << "Could not open file" << endl;
        return 1;
    }

    string line;

    while(getline(dataFile, line)) {
        char space = line.find_last_of(' ');

        string name = line.substr(0, space);
        string birthday = line.substr(space + 1);

        bdayMap[name] = birthday;
    }

    dataFile.close();

    string query;
    while (true)
    {
        cout << "Enter a name and last name or 'exit' to quit" << endl;
        getline(cin, query);

        if (query == "exit")
        {
            break;
        }
        
        auto it = bdayMap.find(query);
        if (it != bdayMap.end())
        { 
            cout << "Birthday: " << it->second << endl;
        } else {
            cout << "Name not found!" << endl;
        }
    }
    
    return 0;
}
