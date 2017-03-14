/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
#include <iostream>

using namespace std;
struct ListNode {
	int val;
	int length;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* creatList(ListNode* l1, int val)
{
	//用尾插入，另一种直接在l1->val=val;l1->next = new ListNode(0);
	//始终末尾多一个0,所以采用如下
	l1->next = new ListNode(val);
	l1 = l1->next;
	return l1;
}
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* ans = new ListNode(0);
		ListNode* head = ans;
		int carry = 0;
		while (l1 != NULL || l2 != NULL)
		{
			int val1 = 0, val2 = 0;
			if (l1 != NULL)
			{
				val1 = l1->val;
				l1 = l1->next;
			}
			if (l2 != NULL)
			{
				val2 = l2->val;
				l2 = l2->next;
			}
			int temp = val1 + val2 + carry;
			head->next = new ListNode(temp % 10);
			head = head->next;
			carry = temp / 10;
		}
		if (carry == 1)
			head->next = new ListNode(1);
		return ans->next;
	}
};

int main()
{
	ListNode* l1 = new ListNode(0), *l2 = new ListNode(0), *ans = new ListNode(0);
	ListNode *p1 = l1, *p2 = l2;
	Solution dx;
	int t;
	for (int i = 0; i<3; i++)
	{
		cin >> t;
		p1 = creatList(p1, t);
	}
	for (int i = 0; i<3; i++)
	{
		cin >> t;
		p2 = creatList(p2, t);
	}
	/*p1->next=new ListNode(2);
	p1=p1->next;
	p1->next=new ListNode(4);
	p1=p1->next;
	p1->next=new ListNode(3);
	p1=p1->next;
	p1->next = NULL;
	p2->next=new ListNode(5);
	p2=p2->next;
	p2->next=new ListNode(6);
	p2=p2->next;
	p2->next=new ListNode(4);
	p2=p2->next;
	p2->next = NULL;*/
	ans = dx.addTwoNumbers(l1->next, l2->next);
	while (ans != NULL)
	{
		cout << ans->val;
		ans = ans->next;
	}
	return 0;
}