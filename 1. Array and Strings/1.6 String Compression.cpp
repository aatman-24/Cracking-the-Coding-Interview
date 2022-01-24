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

Question: 1.6 String Compression
        : Given aaabbcdd return encoding this a2b2c1d2. 

Topic : String

Problems : 

==============================> Explanation <=============================================

- Creart new String, use two pointer to count occurance and return that string.
- Adding into string take O(N^2) time.

Improvement:

- Use vector or java in StringBuilder to make string.
- Second Improvement is first check created new string is less than currnet string.

==============================> Apporach and Time Complexity <=============================================

1) Two Pointer/logic
Time: O(N)
Space: O(1)

*/


