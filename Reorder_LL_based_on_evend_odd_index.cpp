#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to rearrange the linked list
ListNode *oddEvenList(ListNode *head)
{
    if (head == nullptr)
        return head;

    ListNode *odd = head, *even = head->next, *evenHead = even;

    while (even != nullptr && even->next != nullptr)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

// Function to print the linked list
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Take input from user
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        ListNode *newNode = new ListNode(x);
        if (head == nullptr)
        {
            head = newNode;
            tail = head;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    head = oddEvenList(head);

    cout << "Reordered list: ";
    printList(head);

    return 0;
}
