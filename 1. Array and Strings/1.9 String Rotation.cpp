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

Question: 1.9 String Rotation
          - For given string s1 find wheather s2 is a rotation of s1 using only one call to isSubstring.

Topic : String

Problems : 

==============================> Explanation <=============================================

s1 = xy = "waterbottle"
x = wat
y = erbottle


s2 = yx = "erbottlewat"

What is need to identify is ?

- From which index rotation is made... if we identify that then it is very easy to retrive original string.

Brute Force:

- Try for each index to partition string into two part and make the new string by joining the string into reverse
order. Example... s1s2 -> s2s1(new string)

But that take O(N) call to isSubstring.


Trick + Optimized:

- We make new string s1 + s1 and check s2 is substring into that string or not.

- We don't need to figure out which point rotation is made, we directly get the answer.

Because s1 + s1 contains all rotation points.


==============================> Apporach and Time Complexity <=============================================

1) All Approach
Time: O(N)
Space: O(N)

*/

bool isRotation(string s1, string s2) {


    int len = s1.size();
    if(len == s2.size() && len > 0) {

        string s1s1 = s1 + s1;
        return isSubstring(s1s1, s2);
    }


    return false;
}