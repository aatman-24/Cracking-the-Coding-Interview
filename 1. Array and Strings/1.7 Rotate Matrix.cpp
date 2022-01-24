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

Question: 1.7 Rotate Matrix
        : Rotate the Matrix 90 degree/180 degree/270 degree. 

Topic : Matrix

Problems : 

==============================> Explanation <=============================================

Very Popular Apporach:

https://github.com/aatman-24/DSA/blob/main/LeetCode/Medium/48.%20Rotate%20Image.cpp

Clock Wise 90 Degree -> Reverse the matrix by array + Symmentry Roataion
AntiClock Wise 90 Degree -> Reverse all the array + Symmentry Roataion

Cracking the coding interview Approach:

Matrix:

a b c d
e f g h
i j k l
m n o p

Without using Extra Space:

We rotate the index value of position in all direction.... How ?

temp = top
top = left
left = bottom
bottom = right
right = temp.

temp = a
a = m
m = p
p = d
d = temp(a).

We perform this in level wise. First outer layer then come into inside level...

Here only 2 layer is formed. Outer layer and inner layer(fgjk).




==============================> Apporach and Time Complexity <=============================================

1) Two Pointer/logic
Time: O(N)
Space: O(1)

*/


void rotate(int mat[][], int n) {

    for(int layer = 0, layer < n/2; layer++) {

        // first and last element index in layer.
        int first = layer;
        int last =  n - 1 - layer;

        for(int i = first; i < last; i++) {

            // offset is used to calculate index from backward(last pointer.)
            // i is used to calculate the index from forward(first pointer).
            int offset = i - first;


            int top = mat[first][i];


            // Remember: only x and offset decide which index is picked. So it is change every time. First and last decide
            // location of layer. And which value to put into [][] is based on which side moves how. Example...
            // bottom side move <- this direction so its y axis value change based on last-offset. that is how you decide.

            // left -> top
            mat[first][i] = mat[last-offset][first];        

            // bottom -> left
            mat[last-offset][first] = mat[last][last-offset];          

            // right -> bottom
            mat[last][last-offset] = mat[i][last];

            // top -> right
            mat[i][last] = top;

        }


    }

}