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

Question: 1.8 Zero Matrix
        - Set entire row and column to zero if mat[i][j] = 0.

Topic : Array, Matrix

Problems : 

==============================> Explanation <=============================================

Already covered this question in leetcode.

Brute Force: Use another matrix O(N*M)

Use Single Row and Single Column: O(N) + O(M)

Use Two variable firstRow and firstCol and after that set mat[i][0] or mat[0][j].. when mat[i][j] == 0.

https://github.com/aatman-24/DSA/blob/main/LeetCode/Medium/73.%20Set%20Matrix%20Zeroes.cpp

==============================> Apporach and Time Complexity <=============================================

1) All Approach
Time: O(N*M)
Space: O(N*M) -> O(N) + O(M) -> O(1)

*/

