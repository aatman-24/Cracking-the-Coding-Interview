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

Question : 2.7 Intersection
Topic : 
Problems : 

==============================> Explanation <=============================================

How to determine both LL intersect or not ?

Approach 1: Use hashtable put one LL node into it and check other LL node find into hashtable or not.

Approach 2: If both LL intersect then tail of both LL is same else distinct.


Now once we found that, LL are intersecting... How to find intersecting node ?

Approach 1:

    - find length of both LL.
    - Skip the (longest - shortest) node from longer.
    - Now use two pointer, longer and shorter until both are same forward that pointer.
    - Return mathced pointer.

Approach 2:

    - save head1 and head2.
    - forward both node, if one of the node is null, make the it head of opposite LL.
    - both pointer traverse the same distance so it will become same that is intersection node. 


==============================> Apporach and Time Complexity <=============================================

1) Two Pointer
Time: O(N)
Space: O(1)

*/

ListNode* getTail(ListNode* head, int &len1) {

    while(head -> next != nullptr) {
        head = head -> next;
        len1++;
    }

    return head;
}

ListNode* skipKthNode(ListNode* head, int k) {

    while(k > 0 && head != nullptr) {
        head = head -> next;
        k--;
    }

    return head;
}


ListNode* findIntersection(ListNode* list1, ListNode* list2) {

    if(list1 == nullptr || list2 == nullptr)
        return nullptr;

    int len1 = 0, len2 = 0;
    ListNode* tail1 = getTail(list1, len1);
    ListNode* tail2 = getTail(list2, len2);

    if(tail1 != tail2) 
        return nullptr;

    ListNode* shorter = (len1 < len2) ? list1 : list2;
    ListNode* longer = (len1 > len2) ? list2 : list1;

    longer = skipKthNode(longer, abs(len1-len2));

    while(longer != shorter) {
        longer = longer -> next;
        shorter = shorter -> next;
    }

    return longer;

}





ListNode* findIntersection(ListNode* list1, ListNode* list2) {

    if(list1 == nullptr || list2 == nullptr)
        return nullptr;

    int len1 = 0, len2 = 0;
    ListNode* tail1 = getTail(list1, len1);
    ListNode* tail2 = getTail(list2, len2);

    // no intersection found.
    if(tail1 != tail2) 
        return nullptr;

    
    ListNode* head1 = list1, *head2 = list2;

    while(head1 != head2) {
        
        head1 = head1 -> next;
        
        head2 = head2 -> next;
        
        if(head1 == nullptr)
            head1 = head2;

        if(head2 == nullptr)
            head2 = head1;
    }

    return head1;

}