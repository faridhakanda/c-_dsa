// singly linked list implementation using c++
#include <iostream>
using namespace std;

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *create_list(int A[], int n) {
    Node *head = NULL, *temp = NULL, *current;
    int i;
    for (i = 0; i < n; i++) {
        temp = (Node *)malloc(sizeof(Node));
        temp->data = A[i];
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            current =  temp;
        } else {
            current->next = temp;
            current = current->next;
        }
    }
    return head;
}

void display_list(Node *head) {
    while (head != NULL) {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

void insert_beginning(Node *head, int data)  {
    Node *current = (Node *)malloc(sizeof(Node));
    current->data = data;
    current->next = head;
    head = current;
    display_list(head);
}

void insert_end(Node *head, int data) {
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    current->next = new_node;
    display_list(head);
}

void insert_before(Node *head, int position, int data) {
    Node *current = head;
    int index = 0;
    while (current != NULL) {
        index++;
        if (index == position-1) {
            Node *new_node = (Node *)malloc(sizeof(Node));
            new_node->data = data;
            new_node->next = current->next;
            current->next = new_node;
        }
        current = current->next;
    }
    display_list(head);
}

void insert_after(Node *head, int position, int data) {
    Node *current = head;
    int index = 0;
    while (current != NULL) {
        index++;
        if (index == position) {
            Node *new_node = (Node *)malloc(sizeof(Node));
            new_node->data = data;
            new_node->next = current->next;
            current->next = new_node;
        }
        current = current->next;
    }
    display_list(head);
}

void delete_beginning(Node *head) {
    Node *current = head;
    head = head->next;
    free(current);
    cout<<"Delete First node of the List:"<<endl;
    display_list(head);
}
void delete_end(Node *head) {
    Node *current = (Node *)malloc(sizeof(Node));
    current->next = head;
    Node *temp = current;
    while (current->next != NULL) {
        temp = current;
        current = current->next;
    }
    temp->next = NULL;
    free(current);
    cout<<"Delete the End node of the List:"<<endl;
    display_list(head);
}

void delete_any(Node *head, int data) {
    Node *current = (Node *)malloc(sizeof(Node));
    current->next = head;
    Node *temp = current;
    while (temp->next != NULL) {
        if (temp->next->data == data) {
            temp->next = temp->next->next;
            break;
        } else {
            temp = temp->next;
        }
    }
    free(current);
    cout<<"Delete "<<data<<" From the List: "<<endl;
    display_list(head);
}

int search_node(Node *head, int data) {
    int i = 0;
    while (head != NULL) {
        if (head->data == data) {
            return i;
        }
        i++;
        head = head->next;
    }
    return -1;
}

void reverse_list(Node *head) {
    Node *next = NULL, *prev = NULL;
    while (head != NULL) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    head = prev;
    cout<<"Reverse the list: "<<endl;
    display_list(head);
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    int n = 5;
    Node *head;
    head = create_list(A, n);
    display_list(head);

    insert_beginning(head, 111);
    insert_end(head, 999);
    insert_before(head, 3, 444);
    insert_after(head, 3, 555);

    //delete_beginning(head);
    //delete_end(head);
    delete_any(head, 5);

    cout<<"Index of current node: "<<search_node(head, 444)<<endl;

    reverse_list(head);
    

    return 0;
}