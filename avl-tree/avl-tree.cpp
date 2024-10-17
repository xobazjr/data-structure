#include <iostream>
#include <queue>
using namespace std;

class node {
	public:
    	int key;
    	node *left;
    	node *right;
    	int height;
    
    	node(int k){
        	key = k;
        	left = NULL;
        	right = NULL;
        	height = 1;
    	}
};

class avl {
	public:
    	node *r;
    
    	avl(){
        	r = NULL;
    	}

    	static const int ALLOWED_IMBALANCE = 1;

    	int height(node *t){
        	return t == NULL ? 0 : t->height;
    	}

    	void balance(node *&t){
        	if(t == NULL){
        		return;	
			} 
        	if(height(t->left) - height(t->right) > ALLOWED_IMBALANCE){
            	if(height(t->left->left) >= height(t->left->right)){
                	rotateWithLeftChild(t);
            	}else{
                	doubleWithLeftChild(t);
            	}
        	}else if (height(t->right) - height(t->left) > ALLOWED_IMBALANCE){
            	if (height(t->right->right) >= height(t->right->left)){
                	rotateWithRightChild(t);
            	}else{
                	doubleWithRightChild(t);
            	}
        	}t->height = max(height(t->left), height(t->right)) + 1;
    	}

    void insert(int key){
        insert(key, r);
    }

    void insert(int key, node *&t){
        if(t == NULL){
            t = new node(key);
        }else if (key < t->key){
            insert(key, t->left);
        }else if (key > t->key){
            insert(key, t->right);
        }
        balance(t);
    }

    void rotateWithLeftChild(node *&k2){
        node *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        k1->height = max(height(k1->left), k2->height) + 1;
        k2 = k1;
    }

    void rotateWithRightChild(node *&k1){
        node *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->height = max(height(k1->left), height(k1->right)) + 1;
        k2->height = max(height(k2->right), k1->height) + 1;
        k1 = k2;
    }

    void doubleWithLeftChild(node *&k3){
        rotateWithRightChild(k3->left);
        rotateWithLeftChild(k3);
    }

    void doubleWithRightChild(node *&k1){
        rotateWithLeftChild(k1->right);
        rotateWithRightChild(k1);
    }

    node* findMin(node* t){
        if(t == NULL){
            return NULL; 
        }else if (t->left == NULL){
            return t; 
        }else {
            return findMin(t->left); 
        }
    }

    void print(node* root){
        if (root != NULL){
            cout << root->key << " ";
            print(root->left);
            print(root->right);
        }
    }

    void remove(int key, node *&t){
        if (t == NULL){
            return;
        }
        if (key < t->key){
            remove(key, t->left);
        }else if (t->key < key){
            remove(key, t->right);
        }else if (t->left != NULL && t->right != NULL){
            t->key = findMin(t->right)->key;
            remove(t->key, t->right);
        }else{
            node *oldNode = t;
            t = (t->left != NULL) ? t->left : t->right;
            delete oldNode;
        }
        balance(t);
    }
};

int main(){
    avl obj;
    char cmp;
    int key;

    do{
        cin>>cmp;
        if(cmp == 'a'){
            cin>>key;
            obj.insert(key);
        }else if (cmp == 'p'){
            if(obj.r != NULL){
            	obj.print(obj.r);	
            	cout<<endl;
			}
        }else if(cmp == 'd'){
        	cin>>key;
        	obj.remove(key,obj.r);
		}
    }while(cmp != 'x');

    return 0;
}
