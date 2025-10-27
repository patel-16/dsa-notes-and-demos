#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <deque>

typedef long long ll;
typedef unsigned long ull;

using namespace std;

// the fundamental unit -> A node or more precisely an "array node" with an
// array of references to 26 nodes, (lowercase alphabets). Each of those 26 nodes would have
// reference to 26 nodes and so on
class Node {
    public:
        // the array of references to other 26 'array nodes'
        // character identified by index of the array
        // (P.O - I guess if not identifiable by index of array, do you think a 
        // hashmap would have been needed?)
        Node* alphabetList[26];
        
        // count of words that 'pass through but not end' at this node
        int countPrefix;// = 0;


        // count of words that 'pass through && end' at this node
        int countEnd;// = 0;
        
        // redundant -> I think not needed since countEnd is there anyways
        // due to some legacy code
        bool isEnd;/// = false;


        // initialize with constructor
        Node() {
            countPrefix = 0;
            countEnd = 0;
            isEnd = false;

            for (int i = 0 ; i < 26; i++) {
                alphabetList[i] = nullptr;
            }
        }
        
        void insertChar(char c, bool isEnd, bool isNew) {
            if (isNew)
                alphabetList[c - 'a'] = new Node();
            if (isEnd) {
                alphabetList[c - 'a'] -> countEnd += 1;
            }
            alphabetList[c - 'a'] -> countPrefix += 1;
            
        }

    
        bool checkExist(char c) {
            return alphabetList[c - 'a'] != nullptr;
        }

        void setNull(char c) {
            alphabetList[c - 'a'] = nullptr;
        }

        Node* getNext(char c) {
            return alphabetList[c - 'a'];
        }
        
        // void removeChar(char c) {
            
        //     if (alphabetList[c - 'a'] != nullptr) {
        //         alphabetList[c - 'a'] -> countEnd-=1;
        //         alphabetList[c - 'a'] -> countPrefix-=1;

        //         if (alphabetList[c - 'a'] -> countEnd == 0
        //             && alphabetList[c - 'a'] -> countPrefix == 0) {
        //                 alphabetList[c - 'a'] = nullptr;
        //         }

        //     }
        
        // }

};

class Trie {
	public:

        Node* root;

	    Trie() {
	        root = new Node();
	    }

	    void insert(string word) {
            Node* current = root;
	        for (int i = 0; i < word.size(); i++) {
                if ( ! current -> checkExist(word[i])) {
                    current -> insertChar(word[i], i == word.size() - 1, true);
                } else {
                    current -> insertChar(word[i], i == word.size() - 1, false);
                }

                current = current -> getNext(word[i]);
            }
            current -> isEnd = true;
    	}

        bool search(string word) {
            Node* current = root;
            for (int i = 0; i < word.size(); i++)
            {
                if (! current -> checkExist(word[i])) {
                    return false;
                } else {
                    current = current -> getNext(word[i]);
                }
            }
            return current -> isEnd;
        }

        bool startsWith(string word) {
            Node* current = root;
            for (int i = 0; i < word.size(); i++)
            {
                if (! current -> checkExist(word[i])) {
                    return false;
                } else {
                    current = current -> getNext(word[i]);
                }
            }
            return true;
        }

	    int countWordsEqualTo(string word) {
	        Node* current = root;
            for (int i = 0; i < word.size(); i++)
            {
                if (! current -> checkExist(word[i])) {
                    return 0;
                } else {
                    current = current -> getNext(word[i]);
                }
            }
            return current -> countEnd;
    	}

	    int countWordsStartingWith(string word) {
	        Node* current = root;
            for (int i = 0; i < word.size(); i++)
            {
                if (! current -> checkExist(word[i])) {
                    return 0;
                } else {
                    current = current -> getNext(word[i]);
                }
            }
            return current -> countPrefix;
    	}

	    void erase(string word) {
	        Node* current = root;
            Node* prev = current;
            for (int i = 0; i < word.size(); i++)
            {
                if (! current -> checkExist(word[i])) {
                    return;
                } else {
                    current = current -> getNext(word[i]);   
                }
                current -> countPrefix -= 1;
                
                if (i == word.size() -1) {
                    current -> countEnd -= 1;
                }
            }
	    }
};

int main() {

    Trie* obj = new Trie();

    /*
    obj->insert("mango");
    int param_2 = obj->countWordsEqualTo("apple");
    obj->insert("app");
    int param_3 = obj->countWordsStartingWith("app");
    obj->erase("app");
    // int param_4 = obj->countWordsEqualTo("work");
    int param_5 = obj->countWordsStartingWith("app");
    
    cout<<param_2<<" "<<param_3<<"\n";
    cout<<"param_4"<<" "<<param_5<<"\n";
    */

    cout<<"Welcome to Trie demo !\n";
    while (true)
    {
        string queryString;
        cout<<"query string please (lowercase alphabets please)"<<"\n";
        cin>>queryString;

        // TODO - > Later add input validation if needed
        // as of now only lowercase alphabets

        cout<<"\n Select Action \n";
        cout << "1 for Insert\n";
        cout << "2 for Delete\n";
        cout << "3 for Get word count - exact\n";
        cout << "4 for Get word count - prefix \n";

        // TODO - add later
        // cout << "5 for Entire tree diagram \n";
        
        string action;
        cin >> action;
        // for some reason switch can't be used for
        // strings...maybe check later
        
        if (action == "1") {

            obj->insert(queryString);
            cout<<"\n";
        
        } else if (action == "2") {
        
            obj->erase(queryString);
            cout<<"\n";
        
        } else if (action == "3") {
        
            int freq = obj->countWordsEqualTo(queryString);
            cout<<"Exact word count - "<<freq<<"\n\n";
        
        } else if (action == "4") {
        
            int freq = obj->countWordsStartingWith(queryString);
            cout<<"Prefix count - "<<freq<<"\n\n";
        
        } else if (action == "5") {
        
            cout<<"Coming later visualization (probably multithreaded) - \n";
            // The idea is to keep one thread for user interaction and another for 
            // displaying almost-real-time visualization
            // say for instance as soon as user adds a node in terminal one,
            // terminal 2 showing output should be updated
        
        }
        else {
            cout << "invalid input\n";
        }

    }
    

    return 0;
    
}

/*
Input : ["Trie", "insert", "countWordsEqualTo", "insert", "countWordsStartingWith", "erase", "countWordsStartingWith"]

[ [], ["apple"], ["apple"], ["app"], ["app"], ["apple"], ["app"] ]


Output : [null, null, 1, null, 2, null, 1]


Explanation :

Trie trie = new Trie()

trie.insert("apple")

trie.countWordsEqualTo("apple")  // return 1

trie.insert("app") 

trie.countWordsStartingWith("app") // return 2

trie.erase("apple")

trie.countWordsStartingWith("app")   // return 1

Input : ["Trie", "insert", "countWordsEqualTo", "insert", "erase", "countWordsStartingWith"]

[ [], ["mango"], ["apple"], ["app"], ["app"], ["mango"] ]

*/