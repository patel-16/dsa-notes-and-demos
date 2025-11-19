// TreeNodeSimple.h

// yet to put some study in how .h files are prepared
// got this from perplexity
// also the g++ needs to now cover all files
// and thus cmake etc needed for large projects to compile all files
// I think instead of g++ file1.cpp file2.cpp ....and so on 
class TreeNode {
    public:
        // self referencing is a wonderful thing now...
        // but since it's a class, it will point to some other object
        // of the same class, also they can only be pointers, 
        // as if we remove the * below we get incomplete class definition error
        // which seems reasonable.
        
    
        int val;
        TreeNode* left;
        TreeNode* right;
        // ... methods and constructors
        

        TreeNode(int val)
        {
            this -> val = val;
        }
};
