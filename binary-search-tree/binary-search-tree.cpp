#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    node* right;
    node* left;
    int value = 0;
    node(int v) {
        value = v;
        left = NULL;
        right = NULL;
    }
};

class tree {
public:
    node* r;
    tree() {
        r = NULL; 
    }

    void add(int value) {
        if (r == NULL) {
            r = new node(value); 
            return;
        }
        node* n = r;
        while (true) {
            if (n->value > value && n->left != NULL) {
                n = n->left;
            } else if (n->value <= value && n->right != NULL) {
                n = n->right;
            } else if (n->value > value && n->left == NULL) {
                n->left = new node(value);
                break;
            } else if (n->value <= value && n->right == NULL) {
                n->right = new node(value);
                break;
            } else {
                break;
            }
        }
    }

    node* minValueNode(node* n) {
        node* current = n;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }

    node* remove(node* root, int value) {
        if (root == NULL)
            return root;

        if (value < root->value) {
            root->left = remove(root->left, value);
        } else if (value > root->value) {
            root->right = remove(root->right, value);
        } else {
            if (root->left == NULL) {
                node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                node* temp = root->left;
                delete root;
                return temp;
            }

            node* temp = minValueNode(root->right);
            root->value = temp->value;
            root->right = remove(root->right, temp->value);
        }
        return root;
    }

    void breadth_first_traversal() {
        if (r == NULL) return;
        queue<node*> q;
        q.push(r);
        while (!q.empty()) {
            int size = q.size();
            while (size > 0) {
                node* n = q.front();
                q.pop();
                cout << n->value << ",";
                if (n->left != NULL) q.push(n->left);
                if (n->right != NULL) q.push(n->right);
                size--;
            }
            cout << "|";
        }
        cout << endl;
    }

    void inorder_traversal(node* n) {
        if (n != NULL) {
            inorder_traversal(n->left);
            cout << n->value << ",";
            inorder_traversal(n->right);
        }
    }

    void preorder_traversal(node* n) {
        if (n != NULL) {
            cout << n->value << ",";
            preorder_traversal(n->left);
            preorder_traversal(n->right);
        }
    }

    void postorder_traversal(node* n) {
        if (n != NULL) {
            postorder_traversal(n->left);
            postorder_traversal(n->right);
            cout << n->value << ",";
        }
    }
};

int main() {
    tree t;
    char cmp;
    int value;

    do {
        cin >> cmp;
        if (cmp == 'a') {
            cin >> value;
            t.add(value);
        } else if (cmp == 'b') {
            t.breadth_first_traversal();
        } else if (cmp == 'i') {
            t.inorder_traversal(t.r);
            cout << endl;
        } else if (cmp == 'p') {
            t.preorder_traversal(t.r);
            cout << endl;
        } else if (cmp == 't') {
            t.postorder_traversal(t.r);
            cout << endl;
        } else if (cmp == 'd') {
            cin >> value;
            t.r = t.remove(t.r, value);
        }
    } while (cmp != 'x');

    return 0;
}
