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

Question : 2.8 Loop Detection & Loop Begining Node.
Topic : Two Pointer
Problems : 

==============================> Explanation <=============================================


==============================> Apporach and Time Complexity <=============================================

1) Two Pointer
Time: O(N)
Space: O(1)

*/

ListNode* findBeginningOfLoop(ListNode* head) {

    ListNode* slow = head;
    ListNode* fast = head;

    // until both are not same.
    // if no loop then, either fast or fast->next is null.
    while(fast != nullptr && fast -> next != nullptr) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast)
            break;
    }

    // no loop.
    if(fast == nullptr || fast -> next == nullptr)
        return null;

    // move slow at the begining of LL. and take single step.
    slow = head;
    while(slow != fast) {
        slow = slow -> next;
        fast = fast -> next;
    }

    // return fast.
    return fast;
}