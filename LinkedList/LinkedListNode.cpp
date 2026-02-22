#include <iostream>
using namespace std;

class LinkedListNode {

    // the usual 'self reference' 
    // (in syntactical sense, not of the actual object)
    // similar to tries (array of 'self reference'), trees
    // etc..

    public:

    // check if this is correct way to set defaults ??
    LinkedListNode* next = nullptr;

    int value;

};

// well just for refreshers...
// this is how we envision LL..
// value1 -> value2 -> value3 -> .... -> nullptr
// nullptr is used to determine what is the end  
LinkedListNode* buildLLFromVectorAndGetHead(vector <int> &inputVector) {

    LinkedListNode* headNode = nullptr;
    LinkedListNode* currentNode = nullptr;

    for (int i = 0; i < inputVector.size(); i++)
    {
        if (i == 0) {
            
            headNode = new LinkedListNode(); // (default constuctor will be initialized as I defined none)
            
            headNode -> value = inputVector[0]; 
            
            currentNode = headNode;

            continue;
        
        }

        LinkedListNode* newNode = new LinkedListNode();
        newNode -> value = inputVector[i];

        currentNode -> next = newNode;

        // just reference reassigned...language compilers are cool things...
        currentNode = newNode;

    }

    return headNode;

}

void iterateAndPrintLinkedList(LinkedListNode* head) {
    

    LinkedListNode* current = head;

    while (current != nullptr)
    {
        cout<<current -> value<<" ";
        current = current -> next;
    }

    cout<<"\n";
    
}


int main() {


    vector<int> v = {1,3,5,6,7,8};

    LinkedListNode* head = buildLLFromVectorAndGetHead(v);

    iterateAndPrintLinkedList(head);

    return 0;
}