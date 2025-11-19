#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <deque>
#include "TreeNodeBasic.h"

typedef long long ll;
typedef unsigned long ull;

using namespace std;

/*
class TreeNode {
    public:
        int val;
        
        // self referencing is a wonderful thing now...
        // but since it's a class, it will point to some other object
        // of the same class, also they can only be pointers, 
        // as if we remove the * below we get incomplete class definition error
        // which seems reasonable.
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int val) {
            this -> val = val;
        }
        
};
*/

int main() {

    // pointer initialization..nothing to do with constructor??
    TreeNode* rootPointerDummy;
    // for a small exp with pointers...
    cout << rootPointerDummy -> val <<"\n"; // garbage when I tested
    
    rootPointerDummy = new TreeNode(1); // initialized..
    cout << rootPointerDummy -> val <<"\n"; // value


    TreeNode rootPointer(5); // object as per the constructor  
    rootPointer.left = nullptr;
    rootPointer.right = nullptr;
    cout << rootPointer.val <<"\n";
    cout << rootPointer.left <<"\n";
    cout << rootPointer.right <<"\n";

    
    
    return 0;
    
}
