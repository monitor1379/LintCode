// 380. 两个链表的交叉
// 请写一个程序，找到两个单链表最开始的交叉节点。
//
// 注意事项
// 如果两个链表没有交叉，返回null。
// 在返回结果后，两个链表仍须保持原有的结构。
// 可假定整个链表结构中没有循环。
//
// 样例
// 下列两个链表：
//
// A:          a1 → a2
//                   ↘
//                     c1 → c2 → c3
//                   ↗
// B:     b1 → b2 → b3
// 在节点 c1 开始交叉。
//
// 挑战
// 需满足 O(n) 时间复杂度，且仅用 O(1) 内存。

// author : monitor1379
// date : 2016-04-11

// hint : 参考博客
// https://github.com/hit9/oldblog/blob/gh-pages/blog-src/blog/C/posts/25.mkd#9%E6%89%BE%E4%B8%A4%E4%B8%AA%E9%93%BE%E8%A1%A8%E7%9B%B8%E4%BA%A4%E7%9A%84%E4%BA%A4%E7%82%B9



#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    /**
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA, *pB, *k, *pL, *pS;
        for(pA = headA, pB = headB; pA && pB; pA = pA->next, pB = pB->next);
        k = pA == NULL ? pB : pA;
        pL = pA == NULL ? headB : headA;
        pS = pA == NULL ? headA : headB;
        for(; k; k = k->next, pL = pL->next);
        for(; pL != pS; pL = pL->next, pS = pS->next);
        return pL;
    }
};


int main()
{
    ListNode *headA = new ListNode(1);
    headA->next = new ListNode(2);

    ListNode *headB = new ListNode(3);
    headB->next = new ListNode(4);

    headA->next->next = new ListNode(5);
    headB->next->next = headA->next->next;

    Solution s;
    cout << s.getIntersectionNode(headA, headB)->val << endl;

    return 0;
}
