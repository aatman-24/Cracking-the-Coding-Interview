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

Question: 1.1 is Unique
        : Implement an algorithm to determine if a string has all unique characters. What if you can not use additional 
          data Structure ?    

Topic : Array and String

Problems : 

==============================> Explanation <=============================================
For the string we can assume two character sets.
1) ASCII: 128 unique characters. (256 Extended Characterset)
2) Unicode:

Ask first to the intervieww... about this.


1) Brute Force: Using Two for loop check any of same characters are present in string or not.

2) Sorting: Sort the String and check neighbors are same or not.

3) Mapping:

    A) Use ordered_map or unordered_map.
    B) Use array as map.
    3) Bit Manipulation. O(1) (Assumption: Only smaller case characters are allowed.)

==============================> Apporach and Time Complexity <=============================================

1) Brute Force
Time: O(N^2)
Space: O(1)

2) Sorting:
Time: O(NlogN) + O(N)
Space: O(1)

3) Mapping:
Time: O(N)
Space: O(min(N, C)) -> O(1)......... Where, C  is size of character set. In case of ASCII it is 256.

*/


bool isUniqueChars(string s) {

    if(s.size() > 128) return false;

    map<char, bool> mp;                             // unordered_map works in O(1).

    for(int i = 0; i < s.size(); i++) {

        if(mp.count(s[i])) 
            return false;

        mp[s[i]] = true;
    }

    return true;
}


bool isUniqueChars(string s) {

    if(s.size() > 128) return false;

    int checker = 0;

    for(int i = 0; i < s.size(); i++) {

        int offset = int(s[i] - 'a');

        if(checker & (1 << offset))
            return false;

        checker = checker | (1 << offset);
    }

    return true;
}
