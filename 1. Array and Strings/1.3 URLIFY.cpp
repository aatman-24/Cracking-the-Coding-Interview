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

Question: 1.3 URLIFY
        - Replace space with "%20" character in string.
Topic : Array and String
Problems : 

==============================> Explanation <=============================================
1) Brute Force: Create new String and make the change into that string. String is immutable. Inplace is not possible.

2) Optimized Apporach: Form the char[] array of string so we can update into the array.

==============================> Apporach and Time Complexity <=============================================

1) Brute Force
Time: O(N^2)
Space: O(N)

2) Character Array 
Time: O(N)
Space: O(N)


*/


void replaceSpace(char str[], int trueLength) {

    // count total space in first pass.
    int spaceCount = 0, index , i = 0;
    for(int i = 0; i < trueLength; i++) {
        if(str[i] == ' ')
            spaceCount++;
    }

    // count index(total size) from where we start modifiying the string.
    index = trueLength + 2 * spaceCount;

    for(int i = trueLength - 1; i >= 0; i--) {
        if(str[i] == ' ') {
            str[index - 1] = '0';
            str[index - 2] = '2';
            str[index - 3] = '%';
        }
        else {
            str[index-1] = str[i];
            index--;
        }
    }
}