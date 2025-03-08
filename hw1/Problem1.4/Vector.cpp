/*
CH-231-A
hw1
Redon Jashari
RJASHARI@constructor.university
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> wordVector;
    string words;
    cin >> words;

    while (words != "END")
    {
        wordVector.push_back(words);
        cin >> words;
    }

    if (!wordVector.empty()) {
        for (unsigned int i = 0; i < wordVector.size(); i++)
        {
            if (i == 0)
            {
                cout << wordVector[i];
            } else {
                cout << " " << wordVector[i];
            }
        }
        cout << endl;
    }
    
    vector<string>::iterator begin = wordVector.begin();

    if (!wordVector.empty())
    {
        for (vector<string>::iterator iter = wordVector.begin(); 
            iter != wordVector.end(); iter++)
        {
            if (iter == begin)
            {
                cout << *iter;
            } else {
                cout << "," << *iter;
            }
        }
        cout << endl;
    }
    
    return 0;
}
