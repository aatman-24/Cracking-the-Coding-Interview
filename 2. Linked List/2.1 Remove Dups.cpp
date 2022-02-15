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

Question : 2.1 Remove Dups
            - Remove the duplicate from the Linked List.
            - (Follow up) Don't allow to use extra space.
Topic : Linked List
Problems : 

==============================> Explanation <=============================================
1st Approach:

- Keep track of duplicate by using extra space. we can use map, set...

2nd Approach:

- Using two pointers(two for loops) we detect the duplicate, and remove the runner pointer element from the linkedlist.

==============================> Apporach and Time Complexity <=============================================

1) LinkedList
Time: O(N)
Space: O(N)

2) FollowUP
Time: O(N^2)
Space: O(1)

*/



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 1) O(N) - O(N)
ListNode* deleteDups(ListNode* head) {

    map<int, int> mp;

    ListNode* prev = nullptr;
    ListNode* curr = head;

    while(curr != nullptr) {

        // skip the curr by relink, prev->next = curr->next->next;
        if(mp.count(curr->data)) {
            prev->next = curr->next->next;
        }
        else {
            mp[curr->data] = curr->data;
            prev = curr;
        }
        curr = curr->next;
    }

    return head;
}


// 2) O(N^2) - O(1)
ListNode* deleteDups(ListNode* head) {

    map<int, int> mp;

    ListNode* curr = head;

    while(curr != nullptr) {

        ListNode* runner = curr;

        while(runner->next != nullptr) {

            // remove the link of runner->next
            if(runner->next->data == curr->data) {
                runner->next = runner->next->next;
            }
            else {
                runner = runner->next;
            }
        }

        curr = curr->next;
    }

    return head;
}
