// TODO() -> Learn about header files and organize, something like below 
#include "TreeNodeBasic.h"
#include <vector>
#include <iostream>

using namespace std;

void recurseTree(TreeNode* curr, int index, vector<int>& arr);

TreeNode* getRootForFilledTree(int* arr, int arrSize) {
    
    // I guess this needs a digression...let's see later..
    // such as when denominator gets null or 0 or other validity checks for
    // the input arr

    cout<<arrSize<<"\n";

    TreeNode* root = new TreeNode(arr[0]);

    // trying what comes first to my mind .. 
    // getRootForFilledTree2 later we might add an optimized approach..

    TreeNode* nodeMap[arrSize];
    nodeMap[0] = root;

    for (int i = 1; i < arrSize; i++)
    {
        if (arr[i] == -1) {
            continue;
        }

        //. for validity maybe add null checks later
        // (i-1)/2 will come from observation
        TreeNode* parent = nodeMap[ (i - 1) / 2];


        if (i%2 == 1) {
            parent -> left = new TreeNode(arr[i]);
            nodeMap[i] = parent -> left;
        } else {
            parent -> right = new TreeNode(arr[i]);
            nodeMap[i] = parent -> right;
        }

    }

    return root;

}

vector<int> getArrayFromTree(TreeNode* root) {
    vector<int> arr(0);
    // assuming not null root 

    recurseTree(root, 0, arr);

    return arr;
}

void recurseTree(TreeNode* curr, int index, vector<int>& arr) {

    if (arr.size() <= index) {
        while (arr.size() != index + 1)
        {
            arr.push_back(-1);
        }
    }

    arr[index] = curr->val;

    if (curr -> left != nullptr) {
        recurseTree(curr->left, 2*index + 1, arr);
    }

    if (curr -> right != nullptr) {
        recurseTree(curr->right, 2*index + 2, arr);
    }

}

TreeNode* getRootForFilledTree2(int* arr) {
    // I guess we'll add an optimized version later...
    return nullptr;
}


int main() {

    // it will go something like this
    // we are given an array...
    // which represents binary tree...
    // (maybe later add check for validity...or..)

    // from array representation we'll 
    // convert it to what they call 
    // dynamic node representation (the one with struct/class called Node
    // with left and right child, I guess the most used in problems etc...)

    // from that Node representation, we'll try to convert it back to 
    // array...a cute full circle...

    // int arr [] = {20, 8, 22, 5, 3, 4, 25, nullptr, nullptr, 10 ,14};
    // treating -1 as nullptr
    int arr [] = {20, 8, 22, 5, 3, 4, 25, -1, -1, 10 ,14};

    int arrSize = (sizeof(arr)/sizeof(*arr));



    TreeNode* root = getRootForFilledTree(arr, arrSize);

    cout<<"Till here " << root->val <<"\n";

    vector<int> reconstructedArr = getArrayFromTree(root);

    for (int i = 0; i < reconstructedArr.size(); i++)
    {
        cout<<reconstructedArr[i]<<" ";
    }
    cout<<"\n";
    


    return 0;
}
