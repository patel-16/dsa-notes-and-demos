#include <vector>
#include <iostream>

using namespace std;

// refer to problem.txt for problem statement


/* 

(imp hint) - also refer the example mentioned in LPS array constuction
which will help in overall understanding !!! , also better to visualize in notebook with 2 pointer logic I guess..

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

    ***************************

    the real idea is - 

    to observe the naive O(n x m) algo and   
    
    1. utilizing 2 pointers, where pointer in the target string does not move back...and movement in query pointer shifts optimally


    2. utilizing a preprocessing of the 
    query string that can help us determine "what next index to start with for comparison"

    3. during comparison till the mismatched character there was a match...this info is utilized a lot I believe...

    ***************************

2nd observation -
    - if the query string has to match a sub string of target, then prefix of the query string must match prefix
    of that substring from target...this seems trivial but it is useful to skip some comparisons later. 


3rd observation -
    - on top of 2nd observation...let's say we are dealing with a substring of target and query 
    let's say query[0...currentIndex] matches with target[j...k] but not at currentIndex+1, k+1
    
    - now as for why LPS[currentIndex] works...? (Longest prefix which is also a suffix..for string query[0....currentIndex])

    - if another prefix of query exists in target[j..k] we can move to that index - (1)
    & since there was a match for query[0..currentIndex] to target[j..k], that much part will be the same


Resources - 

https://www.geeksforgeeks.org/dsa/kmp-algorithm-for-pattern-searching/
https://www.youtube.com/watch?v=ynv7bbcSLKE

*/ 


// proper prefix suffix array
// (???? seems it means there should not be character overlap (same index) between the prefix and the suffix)
// longest suffix which is also a suffix 
vector<int> getLongestPrefixSuffixArray(string &query) {

    vector<int> LPSArray(query.size(), 0);

    // proper prefix suffix array
    LPSArray[0] = 0; 

    

    // length of the previous longest prefix suffix
    int matchedPrefixIndex = 0;  // also tracks index in a way... prefixIndex
    int currentIndex = 1;

    while (currentIndex < query.size()) {

        // simple case, if match...increase prefix and current index
        if (query [currentIndex] == query [matchedPrefixIndex]) {
            matchedPrefixIndex++;
            LPSArray [currentIndex] = matchedPrefixIndex;
            currentIndex++;
        } else {
            if (matchedPrefixIndex != 0) { 
                // fall back in the pattern
                // WHY? 
                // if match failed at a index...
                // we look for a smaller index which can be a prefix
                // default case would be to move to 0
                // but again "till the mismatched character there was a match"
                // so we look to the prefix of that 'mismatchedIndex - 1' 
                // which due to variable naming is 'matchedPrefixIndex - 1' here 
                
                matchedPrefixIndex = LPSArray [matchedPrefixIndex - 1];  
                // in the below string 
                // "abyabxabyaby"
                // at the last index (y) this can be observed..
                // And this is also very useful in understanding the KMP as a whole I think
                
            } else {
                LPSArray [currentIndex] = 0;
                currentIndex++;
            }
        }
    }

    return LPSArray;
    

}


vector<int> matchedIndicesWithKMP(string &query, string &target) {
    vector<int> matchedIndices;

    vector<int> LPSArrayOfQueryString = getLongestPrefixSuffixArray(query);

    // 2 pointer...

    int queryPointer = 0;
    int targetPointer = 0;

    while (targetPointer < target.size())
    {
        
        if (query[queryPointer] != target[targetPointer]) {
            

            if (queryPointer == 0) {
                // other than ' - 1 ', the philosophy is there is no 'query' prefix now...
                // to be matched with a 'suffix' of 'target'
                targetPointer += 1;
            } else {
                // the index till which there is a match 'queryPointer - 1'
                queryPointer = LPSArrayOfQueryString [queryPointer - 1]; 
            }
            
        } else {

            if (queryPointer == query.size() - 1) {
                
                matchedIndices.push_back(targetPointer - queryPointer);
                
                
                // queryPointer = 0; -- almost everywhere made this mistake during impl
                // setting 0 instead of LPS(queryPtr)
                // the index till which there is a match, here 'queryPointer' (+1 done later)
                queryPointer = LPSArrayOfQueryString [queryPointer]; 

                // well we do not reset targetPointer because
                // in query string we move to the "prefix" that matched
                // and as for the target, we move to the "suffix" that matched
                // "to be argued...why is this optimal?...and sufficient...?"
                // is it because it's longest ?
                targetPointer += 1;
                queryPointer += 1;
            } else {
                queryPointer += 1;
                targetPointer += 1;
            }

        }

    }
    



    return matchedIndices;
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

    vector <int> matchedIndices = matchedIndicesWithKMP(query, target);

    cout << "\n matched indices are : ";
    for (int i = 0; i < matchedIndices.size(); i++)
    {
        cout << matchedIndices[i] << " ";
    }
    cout<<"\n";
    

}
