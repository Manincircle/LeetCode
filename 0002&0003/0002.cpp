/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;//是否进位
        ListNode* dummy = new ListNode(0);//头节点，不储存结果
        ListNode* current = dummy;//当前节点

        while (l1 || l2 || carry) {//只要还有链表或者进位没有处理就继续
            int sum = carry;//这一位的值
            if (l1) {//如果链表l1没有被处理完
                sum += l1->val;//加上当前链表节点的值
                l1 = l1->next;//到下一个节点
            }
            if (l2) {//同上
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;//这一位和大于九则有一位进位
            current->next = new ListNode(sum % 10);//当前节点的下一个节点储存的值
            current = current->next;//到下一个节点
        }

        return dummy->next;//返回头节点的下一个节点，因为头节点不储存结果
    }
};