#include <vector>
#include <iostream>

using namespace std;

// refer to problem.txt for problem statement

// 

/* 

1st observation - 
    - query string
    // bbcd // 

    - target/doc string
    // a"bbcbbcd"pr"bbct"u"bcb"xa"bbcd"abc //

    The idea is to skip useless comparisons which are guaranteed to fail

    say for the 1st highlight "bbcbbcd" we have to skip "bbc" when the comparison fails with "bbcd"


    in a naive approach one'd try to compare with first and second 'b' in "bbc"

    similarly for naive cases - "aaab" in "aaaaaaaab" if we just search character by character than complexity
    
    will be O(n x m) (n - size of query, m - size of target)


2nd observation -
    - if the query string has to match a sub string of target, then prefix of the query string must match prefix
    of that substring from target...this seems trivial but it is useful to skip some comparisons later. 


3rd observation -
    - on top of 2nd observation...let's say we are dealing with a substring of target and query 
    let's say query[0...i] matches with target[j...k] but not at i+1, k+1
    
    - now as for why LPS[i] works...? (Longest prefix which is also a suffix..for string query[0....i])

    - if another prefix of query exists in target[j..k] we can move to that index - (1)
    & since there was a match for query[0..i] to target[j..k], that much part will be the same


Resources - 

https://www.geeksforgeeks.org/dsa/kmp-algorithm-for-pattern-searching/
https://www.youtube.com/watch?v=ynv7bbcSLKE

*/ 


// proper prefix suffix array
// seems it means there should not be character overlap (same index) between
// the prefix and the suffix 
vector<int> getLongestPrefixSuffixArray(string &s) {

    vector<int> LPSArray(s.size());

    // 
    LPSArray[0] = 0; 

}


int main() {

    cout<<"Enter query string and the target string \n";
    string query;
    string target;
    
    cout<<"\n query - ";
    cin>>query;
    
    // bbcd //
    // 

    cout<<"\n target - ";
    cin>>target;
    // a"bbcbbcd"pr"bbct"u"bcb"xa"bbcd"abc //

}
