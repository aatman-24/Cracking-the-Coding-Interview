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

Question: 1.3 Palindrome Permutation
Topic : Array and String
Problems : 

==============================> Explanation <=============================================
- If string is Palindrome Permutation, then we can arrange the string in permutation order.
- So It is clear we need to count frequency of character.
- For Even length string all characters freq must be even and for the odd length string only one character freq is allowed to odd.
- In short we need to find wheather string contain atleast 1 odd character.

1) Brute Force:

    - make the map and count frequency. 
    - check all freq, only one odd allowed.

2) Optimization:
    
    - we can keep count of oddCount while counting frequency. (small optimization)

3) Bit Manipulation:

    - Our bitVector either contain single set bit or all zero bits.

    - So for single set bit we can perform (bitVector & bitVector-1 == 0) or not to check it have single bit or not.


==============================> Apporach and Time Complexity <=============================================

1) Frequency count
Time: O(N)
Space: O(N) -> O(1)

*/

bool isPermutationOfPalindrome(string s) {

    int mp[26] = {0};

    for(int i = 0; i < s.size(); i++) {
        if('a' <= s[i] && s[i] <= 'z') {
            mp[int(s[i])-int('a')]++;
        }
        else if('A' <= s[i] && s[i] <= 'Z') {
            mp[(int(s[i])-int('a')-34)]++;
        }
        else {
            continue;
        }
    }

    bool foundOdd = false;
    for(int i = 0; i < 26; i++) {
        if(mp[i] % 2 == 1) {
            if(foundOdd)
                return false;
            foundOdd = true;
        }
    }

    return true;
}


bool isPermutationOfPalindrome(string s) {

    int mp[26] = {0};
    int countOdd = 0, offset;

    for(int i = 0; i < s.size(); i++) {
        if('a' <= s[i] && s[i] <= 'z') {
            offset = int(s[i])-int('a');
        }
        else if('A' <= s[i] && s[i] <= 'Z') {
            offset = int(s[i])-int('a')-34;
        }
        else {
            continue;
        }

        mp[offset]++;
            
        if(mp[offset] % 2)
            countOdd++;
        else 
            countOdd--;
    }


    return countOdd <= 1;
}


bool isPermutationOfPalindrome(string s) {

    int bitVector = 0;

    for(int i = 0; i < s.size(); i++) {

        if('a' <= s[i] && s[i] <= 'z') {
            offset = int(s[i])-int('a');
        }
        else if('A' <= s[i] && s[i] <= 'Z') {
            offset = int(s[i])-int('a')-34;
        }
        else {
            continue;
        }

        int mask = 1 << offset;

        if(bitVector & mask == 0) {
            bitVector = bitVector | mask;
        }
        else {
            bitVector = bitVector & ~mask;
        }
                
    }


    return bitVector == 0 || (bitVector & ( bitVector - 1) == 0);
}