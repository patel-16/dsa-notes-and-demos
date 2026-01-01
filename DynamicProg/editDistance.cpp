#include <vector>
#include <iostream>

using namespace std;

// in search in general, a statement I heard somewhere
// edit distance being used to calculated the diff to enumerate
// performance of search etc...

// I think this might be used with Tries in practice ?

// TODO() add time complexity analysis...

///##############################################################################################

int dpTopDown[500+1][500+1];

int editDistanceTopDownRecursion(int sourceInd, int targetInd, string &source, string &target) {

    if (sourceInd == -1 && targetInd == -1) {
        return 0;
    } else if (sourceInd == -1 && targetInd>=0) {
        return targetInd + 1;
    } else if (targetInd == -1 && sourceInd>=0) {
        return sourceInd + 1;
    }

    if (dpTopDown[sourceInd][targetInd] != -1) {
        return dpTopDown[sourceInd][targetInd];
    }


    if (source[sourceInd] != target[targetInd]) {
        int deletion_case = editDistanceTopDownRecursion(sourceInd - 1, targetInd, source, target);
        int replace_case = editDistanceTopDownRecursion(sourceInd - 1, targetInd - 1, source, target);
        int add_case = editDistanceTopDownRecursion(sourceInd, targetInd - 1, source, target); 
        
        dpTopDown[sourceInd][targetInd] = 1 + min(deletion_case, min (replace_case, add_case));
    } else {
        dpTopDown[sourceInd][targetInd] = editDistanceTopDownRecursion(sourceInd-1, targetInd - 1, source, target);
    }


    return dpTopDown[sourceInd][targetInd];
}

int editDistanceTopDown(string source, string target) {

    // I know there are concerns regarding the differences in sizes
    // such as m > n , m == n or m < n
    // So for this we just march on "left to right" or "right to left"
    // maybe while maintaining a thing that the past alphabets are matching

    // also the case with DP is that it ought to have that optimal 
    // substructure property I guess we read long back...that solutions 
    // of parts indeed work up for solution of whole...else DP can't be applied

    // what is imp is what we store here...state....
    // dp[i][j] - optimal cost for converting source[0..i] to target[0..j] 
    // as mentioned above assuming "right to left" movement here
    
    
    int m = source.size();
    int n = target.size();

    for (int i = 0; i < m+1; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            dpTopDown[i][j] = -1;
        }
        
    }
    
    return editDistanceTopDownRecursion(m-1, n-1, source, target);

}

///##############################################################################################

// TODO- finish this...
int editDistanceBottomUp(string source, string target) {
    
    int m = source.size();
    int n = target.size();

    // I know there are concerns regarding the differences in sizes
    // such as m > n , m == n or m < n
    // So for this we just march on "left to right" or "right to left"
    // maybe while maintaining a thing that the past alphabets are matching

    // also the case with DP is that it ought to have that optimal 
    // substructure property I guess we read long back...that solutions 
    // of parts indeed work up for solution of whole...else DP can't be applied

    // what is imp is what we store here...state....
    // dp[i][j] - optimal cost for converting source[0..i] to target[0..j] 
    // as mentioned above assuming "left to right" movement here
    // (we'll make 1 based indexing for convenience)
    int dp[m+1][n+1];
    dp[0][0] = INT_MAX;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++) {

            if (source[i] != target[j]) {
                int deletion_case = dp[i-1][j];
                int replace_case = dp[i-1][j-1];
                int add_case = dp[i-1][j-1];
                // dp[i+1][j+1] = min(dp[i][j], )
            } else {

            }

        }

    }
    
    return -1;
}

///##############################################################################################

int main() {

    cout<<"Enter source string and the target string \n";
    string source;
    string target;
    cout<<"\n source - ";
    cin>>source;
    cout<<"\n target - ";
    cin>>target;


    cout<<"\n Edit distance (with char add, delete and replace) is  - ";

    cout << editDistanceTopDown(source, target) << "\n";

    // cout << editDistanceBottomUp(source, target) << "\n";

    // TODO - the most optimal version. (space opt..)

    return 0;
}