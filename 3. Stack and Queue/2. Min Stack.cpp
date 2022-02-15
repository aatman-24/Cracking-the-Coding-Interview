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

Question : 2. Min Stack
Topic : Stack
Problems : 

==============================> Explanation <=============================================


==============================> Apporach and Time Complexity <=============================================

1) Stack
Time: Each Operation: O(1), O(1)
Space: O(N)

*/


class NodeWithMin {
public:
    int value, min_value;
    NodeWithMin(int value, int min_value) {
        this->value = value;
        this->min_value = min_value;
    }
}


// keep track of min.
class StackMin {

public:

    stack<NodeWithMin> st;

    void push(int value) {

        int newMIn = min(value, minInStack());
        st.push(NodeWithMin(value, newMIn));
    }


    int minInStack() {
        if(st.empty()) {
            return INT_MAX;
        }
        return st.top()->min_value;

    }

};



// Two stack. Save Space.
class StackMin {

public:

    stack<int> st;
    stack<int> minStack;

    void push(int value) {
        st.push(value);
        if(value <= minInStack()) {
            minStack.push(value);
        }
    }

    int pop() {

        int value = st.top(); st.pop();

        if(minInStack() == value) {
            minStack.pop();
        }

        return value;
    }


    int minInStack() {
        if(st.empty()) {
            return INT_MAX;
        }
        return minStack.top();
    }

};