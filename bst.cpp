#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        cout<<"Error Memory allocation failed!"<<endl;
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;

    return newNode;
}

void add_left_child(Node *root, Node *child) {
    root->left = child;
    if (child != NULL) {
        child->parent = root;
    }
}
void add_right_child(Node *root, Node *child) {
    root->right = child;
    if (child != NULL) {
        child->parent = root;
    }
}

Node *bstInsert(Node *root, Node *node) {
    Node *parent, *current;
    if (root == NULL) {
        root = node;
        return root;
    }
    parent = NULL;
    current = root;
    while (current != NULL) {
        parent = current;
        if (node->data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    if (node->data < parent->data) {
        add_left_child(parent, node);
    } else {
        add_right_child(parent, node);
    }
    return root;
}

void inOrder(Node *root) {
    if (root != NULL) {
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

Node *createBST() {
    Node *root, *current;
    root = createNode(25);
    int arr[] = {20, 54, 100, 92, 51, 14, 19, 58, 99, 48, 43, 32, 59, 60, 79};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        current = createNode(arr[i]);
        root = bstInsert(root, current);
    }
    
    return root;
}


// binary search minimum value finding with iterative
Node *bstMin(Node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}
// find min value with recursive way
Node *bstMinR(Node *root) {
    if (root->left != NULL) {
        return bstMinR(root->left);
    }
    return root;
}

// finding max value with iterative way
Node *bstMax(Node *root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}
// finding max value with recursive way
Node *bstMaxR(Node *root) {
    if (root->right != NULL) {
        return bstMaxR(root->right);
    }
    return root;
}


// finding desire value with search
Node *bstSearch(Node *root, int data) {
    while (root != NULL && data != root->data) {
        if (data < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return root;
}
// find value with recursive search
Node *bstSearchR(Node *root, int data) {
    if (root == NULL || data == root->data) {
        return root;
    }
    if (data < root->data) {
        return bstSearchR(root->left, data);
    } else {
        return bstSearchR(root->right, data);
    }
}

// bst successor
Node *bstSuccessor(Node *root) {
    if (root->right != NULL) {
        return bstMin(root->right);
    }
    Node *head = root->parent;
    while (head != NULL && root == head->right) {
        root = head;
        head = head->parent;
    }
    return head;
}
Node *bstPredecessor(Node *root) {
    if(root->left != NULL) {
        return bstMax(root->left);
    }
    Node *head = root->parent;
    while (head != NULL && root == head->left) {
        root = head;
        head = head->parent;
    }
    return head;
}


Node *bstTransplant(Node *root, Node *current, Node *node) {
    if (current == root) {
        root = node;
    } else if (current == current->parent->left) {
        add_left_child(current->parent, node);
    } else {
        add_right_child(current->parent, node);
    }
    return root;
}

Node *bstDelete(Node *root, Node *node) {
    Node *temp;
    if (node->left == NULL) {
        root = bstTransplant(root, node, node->right);
    } else if (node->right == NULL) {
        root = bstTransplant(root, node, node->left);
    } else {
        temp = bstMin(node->right);
        if (temp->parent != node) {
            root = bstTransplant(root, temp, temp->right);
            add_right_child(temp, node->right);
        }
        root = bstTransplant(root, node, temp);
        add_left_child(temp, node->left);
    }
    free(node);
    return root;
}
int main() {
    Node *root = createBST();
    inOrder(root);
    cout<<"\nBST"<<endl;

    Node *temp;
    temp = bstMinR(root);
    cout<<"Min value is: "<<temp->data<<endl;

    temp = bstMaxR(root);
    cout<<"Max value is: "<<temp->data<<endl;

    // search value
    temp = bstSearchR(root, 25);
    if (temp != NULL) {
        cout<<"Search value is: "<<temp->data<<endl;
    } else {
        cout<<"Search value is not found!"<<endl;
    }
    
    Node *del = bstSearchR(root, 32);
    if (del != NULL) {
        cout<<"\nWill delete value is: "<<del->data<<endl;
        cout<<"\nBST: \n";
        root = bstDelete(root, del);
        inOrder(root);
        cout<<endl;
    }
    
    
    temp = bstSuccessor(root);
    cout<<"Successor value is: "<<temp->data<<endl;
    temp = bstPredecessor(root);
    cout<<"Predecessor value is: "<<temp->data<<endl;



    return 0;
}