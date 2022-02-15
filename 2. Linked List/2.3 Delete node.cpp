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

Question : 2.3 Delete node
           - You are not given access to the head of linkedlist. Only delete node access is given.
Topic : Queue
Problems : 

==============================> Explanation <=============================================

- copy the next node data into the current node.
- delete the next node by relink the curr.next = curr.next.next;

WARNING: if given node is last node then we can not perform this opereation. Tell the interviewer about this. you can mark the current node as
         dummy node by changing it value.

==============================> Apporach and Time Complexity <=============================================

1) LinkedList
Time: O(N)
Space: O(1)

*/

bool deleteNode(ListNode* n) {
    if(n == nullptr || n->next == nullptr)
        return false;
    ListNode* next = n->next;
    n->data = next->data;
    n->next = next->next;
    return true;
}
