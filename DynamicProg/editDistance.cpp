#include <vector>
#include <iostream>

using namespace std;

// in search in general, a statement I heard somewhere
// edit distance being used to calculated the diff to enumerate
// performance of search etc...

// I think this might be used with Tries in practice ?

// TODO() add time complexity analysis...
int editDistance(string source, string target) {
    
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
                int deletion_case
                dp[i+1][j+1] = min(dp[i][j], )
            } else {

            }

        }

    }
    
    


}


int main() {

    string s1;
    string s2;

    cin>>s1>>s2;

    return 0;
}