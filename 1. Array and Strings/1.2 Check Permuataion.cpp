#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007
#define eps 1e-6

using namespace std;


typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef map<int,int> mii;


/*
==============================> Description <=============================================

Question: 1.2 Check Permuataion
        : Given a two string, write a function to check if it is a permutation of a palindrome.


Topic : Array and String

Problems : 

==============================> Explanation <=============================================
For the string we can assume two character sets.
1) ASCII: 128 unique characters. (256 Extended Characterset)
2) Unicode:

+ Matching should be case sensitive or not.... consider the whitespace or not.

Ask first to the intervieww... about this.

1) Brute Force: Sort the both string and compare both are same or not.

2) Mapping (Assumption: ASCII):

    A) Use ordered_map or unordered_map.
    B) Use array as map.

2) Mapping with Early Stop:

    - Same as above, but we first count all the occurance of string for string A and then we subtract from the map
      when we encounter into the string B. But any time if it is negative that means in string B additional characters
      are present so we directly return false.

==============================> Apporach and Time Complexity <=============================================

2) Brute Force:
Time: O(NlogN) + O(N)(Same or not)
Space: O(1)

3) Mapping:
Time: O(N)
Space: O(128)


3) Mapping with Early Stop:
Time: O(N)
Space: O(128)

*/

bool isPermutationOfPalindrome(string A, string B) {
    
    if(A.size() != B.size()) 
        return false;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    return A == B;
}



bool isPermutationOfPalindrome(string A, string B) {

    if(A.size() != B.size()) 
        return false;

    map<char, int> mp;                 

    for(int i = 0; i < A.size(); i++) {
        mp[A[i]]++;
        mp[B[i]]--;
    }

    for(auto it: mp) {
        if(it.second != 0)
            return false;
    }

    return true;
}


bool isPermutationOfPalindrome(string A, string B) {

    if(A.size() != B.size()) 
        return false;

    int map[128] = {0};

    for(int i = 0; i < A.size(); i++) {
        mp[A[i]]++;
    }

    for(int i = 0; i < A.size(); i++) {
        
        mp[B[i]]--;

        // we already count the character frequency in A. So if it is negative it means extra
        // character in B.
        if(mp[B[i]] < 0)
            return false;
    }

    // No need to check map contains all zero or not. Because if no negative value in map then all
    // value is zero.

    return true;
}