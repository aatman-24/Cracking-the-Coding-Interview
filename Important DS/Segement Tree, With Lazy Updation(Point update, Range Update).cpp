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

Question : Segement Tree, With Lazy Updation(Point update, Range Update)
Topic : Binary Indexed Tree, Segement Tree
Problems : 

==============================> Explanation <=============================================

Build Tree: https://www.youtube.com/watch?v=-dUiRtJ8ot0
Update and Range Query: https://www.youtube.com/watch?v=rwXVCELcrqU




==============================> Apporach and Time Complexity <=============================================

1) Segement Tree
Time: update: O(logN), query: O(logN)
Space: O(4*n)
*/


int arr[100005], seg[4*100005];


// build the segement tree.
void build(int index, int low, int high) {
    
    // leaf node.
    if(low == high) {
        arr[index] = arr[low];
        return;
    }

    int mid = (low + high) >> 1;

    build(2*index+1, low, mid);
    build(2*index+2, mid+1, high);

    // segement tree for sum query.
    seg[ind] = seg[2*index+1] + seg[2*index+2];
}


int query(int index, int low, int right, int l, int r) {
    
    // [low, l, r,  high] (inside the range)
    if(low >= l && high <= r) {
        return seg[index];
    }

    // outperform. 
    if(high < l || low > r)
        return 0;

    // (overlap)
    int mid = (low + high) >> 1;

    // left and right subtree.
    int left = query(2*index+1, low, mid, l, r);
    int right = query(2*index+2, mid+1, high, l, r);

    // return sum of both.
    return left + right;
}


// 1. Point updation: Increase the value of arr[2] with 5. (keep l = r = 2)
// 2. Range updation: Increase the value of array from [1, 4] with 5. (keep l = 1 and r = 4)

void rangeUpdate(int index, int low, int high, int l, int r, int val) {

    // perform lazy updation first if remaining.
    if(lazy[index] != 0) {

        seg[index] += (high - low + 1) * lazy[index];

        // not the leaf node, save the lazy[index] value to both child.
        if(low != high) {

            lazy[2*index+1] += lazy[index];
            lazy[2*index+2] += lazy[index];
        }

        // make the lazy index 0.
        lazy[index] = 0;
    }

    // outcast.
    if(r < low || l > high || low > high) return;

    // (inside)
    if(low >= l && high <= r) {
        
        seg[index] += (high - low + 1) * val;

        // not the leaf node, save the lazy[index] value to both child.
        if(low != high) {

            lazy[2*index+1] += val;
            lazy[2*index+2] += val;
        }
        else {
            // update the original array.
            arr[low] += val;
        }
        return;
    }

    // (overlap).
    int mid = (low + high) >> 1;
    rangeUpdate(2*index+1, low, mid, l, r);
    rangeUpdate(2*index+2, mid+1, high, l, r);
    seg[index] = seg[2*index+1] + seg[2*index+2];
}



void pointUpdate(int index, int low, int high, int l, int r, int val) {

    // (outcast)
    if(high < l || low > r || low > high)
        return;

    // point update.
    if(low == high) {
        arr[low] += val;
        seg[index] += val;
        return;
    }

    // overlap
    int mid = (low + high) >> 1;
    pointUpdate(2*index+1, low, mid, l, r, val);
    pointUpdate(2*index+2, mid+1, high, l, r, val);

    seg[index] = seg[2*index+1] + seg[2*index+2];
}


int querySumLazy(int index, int low, int high, int l, int r, int val) {

    // remaining lazy operation perform.
    if(lazy[index] != 0) {

        seg[index] += (high - low + 1) * lazy[index];

        // not the leaf node, save the lazy[index] value to both child.
        if(low != high) {

            lazy[2*index+1] += lazy[index];
            lazy[2*index+2] += lazy[index];
        }

        // make the lazy index 0.
        lazy[index] = 0;
    }


    // outcast.
    if(r < low || l > high || low > high) return 0;

    // (inside)
    if(low >= l && high <= r) {
        return seg[index];
    }

    // (overlap).
    int mid = (low + high) >> 1;
    int left = querySumLazy(2*index+1, low, mid, l, r);
    int right = querySumLazy(2*index+2, mid+1, high, l, r);

    return left + right;
}


int main() {

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build(0, 0, n-1);

}