#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class ListLoader {
    private: 
        vector<string> *wordlist;
        int index;

    public: 
        ListLoader() {
            wordlist = new vector<string>();
            index = 0;
        }
    void load(string filename) {    
        index = 0;   
        string line;
        ifstream file (filename);
        if (file.is_open()) {
            while (getline(file,line) ) {
                wordlist->push_back(line);
            }
            file.close();
        }
        else 
            cerr << "Unable to open file " << filename << "\n"; 
        cout << "Loaded " << wordlist->size() << " lines from " << filename;
    }
    
    string getNextWord() {
        if (index > wordlist->size()-1) {
            return "";
        }
        index++;
        return wordlist->at(index-1);
    }
    vector<string>* getFullList() {
        return wordlist;
    }
};
