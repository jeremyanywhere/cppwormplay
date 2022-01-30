#include <iostream>
#include <string>
#include <list>
#include <array>
#include "listloader.h"

using namespace std;

class Node {
    public: 
        int a;
        array<Node*,26> children;

    Node () {
        int a = 0;
        for (int i=0;i<26;i++) {
            children.at(i) = NULL;
        }
    }
    void insertWord(string word, Node *n) {
        int i = word.at(0)-97;
        //System.out.println("Putting in word: " + word + "  At index: "+i);
        if (n->children.at(i) == NULL) {
            n->children.at(i) =  new Node();
        }
        if (word.length() > 1) {
            insertWord(word.substr(1), n->children.at(i));
        }
    }
    void getMatches(string pattern, Node *n, list<string> *matchList, string constructedWord) {
        if (pattern.length()==0) {
            matchList->push_back(constructedWord);
            constructedWord = "";
        } else {
            if (pattern.at(0)=='?') {
                for (int x =0; x < 26; x++) {
                    if (n->children.at(x) != NULL) {
                        getMatches(pattern.substr(1), n->children.at(x), matchList, constructedWord+(char)(x+97));
                    }
                }
            } else {
                int i = pattern.at(0)-97;
                if (n->children.at(i) != NULL) {
                    constructedWord += pattern.at(0);
                    getMatches(pattern.substr(1), n->children.at(i), matchList, constructedWord);
                }
            }
        }
    }
};

int main()
{
    Node *node = new Node();
    array<string,8> words[] = {"bands","banal","boaty","acorn","achey","aches","booty","bahas"};
    for (int i = 0; i < words->size(); i++) {
        node->insertWord(words->at(i), node);
        cout << words->at(i) << " ";
    }
    cout << "\n";
    list<string> *matchlist = new list<string>();
    string pattern = "????s";
    cout << "starting..\n"; 
    node->getMatches(pattern,node,matchlist,"");

    for (list<string>::iterator j = matchlist->begin(); j!= matchlist->end(); j++) {
        cout << " " << *j << "\n";
    }

    delete node;
    ListLoader loader;
    loader.load("griddle5.txt");
    cout << "done.";
}