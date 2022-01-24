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

Question: 1.5 One Away
        : Given two string is one edit(zero edit) or not. Operation: [insert, delete, replace]

Topic : String

Problems : 

==============================> Explanation <=============================================

Brute Force:
- For each position we check all the operation once and then match if both are same or not. 
- But it take too much time.

Optimized Apporach:

- If(abs(s1.size() - s2.size()) > 1) return false.

- (s1.size() == s2.size()) only need to check replace operation. (once we allow mismatch)
- (s1.size() < s2.size()) Insertion in s1.  (once we allow mismatch)
- (s1.size() > s2.size()) Insertion in s2.  (once we allow mismatch)


==============================> Apporach and Time Complexity <=============================================

1) Two Pointer/logic
Time: O(N)
Space: O(1)

*/


bool oneEditAway(string s1, string s2) {

    if(abs(s1.size() - s2.size()) > 1)
        return false;

    if(s1.size() == s2.size()) {
        return replaceEditAway(s1, s2);
    }
    else if(s1.size() < s2.size()) {
        return InsertEditAway(s1, s2);
    }
    else if(s1.size() > s2.size()) {
        insertEditAway(s2, s1)
    }

    return false;
}

bool replaceEditAway(string s1, string s2) {
    bool foundMismatch = false;
    for(int i = 0; i < s1.size(); i++) {
        if(s1[i] != s2[i]) {
            if(foundMismatch)
                return false;
            foundMismatch = true;
        }
    }
    return true;
}

bool insertEditAway(string s1, string s2) {
    int idx1 = 0, idx2 = 0;
    while(idx1 < s1.size() && idx2 < s2.size()) {
        if(s1[idx1] != s2[idx2]) {
            if(idx1 != idx2)
                return false;
            idx2++;
        }
        else {
            idx1++; idx2++;
        }
    }
    return true;
}


// mix both the function into the one.
bool oneEditAway(string s1, string s2) {
    
    if(abs(s1.size() - s2.size()) > 1)
        return false;

    bool foundMismatch = false;
    int idx1 = 0, idx2 = 0;


    string s1 = s1.size() < s2.size() ? s1 : s2;
    string s2 = s1.size() < s2.size() ? s2 : s1;

    while(idx1 < s1.size() && idx2 < s2.size()) {

        if(s1[idx1] != s2[idx2]) {

            if(s1.size() == s2.size()) {
                if(foundMismatch)
                    return false;
                foundMismatch = true;
            }

            if(idx1 != idx2) {
                return false;
            }

            idx2++;
        }
        else {
            idx1++; idx2++;
        }
    }

    return true;
}