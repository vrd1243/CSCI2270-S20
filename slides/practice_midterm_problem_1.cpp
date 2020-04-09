#include <iostream>

using namespace std;

struct BSTNode {
    
	float key;
	BSTNode *left;
	BSTNode *right;
	BSTNode(float key_arg) {
	    key = key_arg;	
	    left = NULL;
	    right = NULL;
	}
};

BSTNode * root;

void sumRangeHelper(BSTNode * node, float & count, int min, int max) {
    
    if (node == NULL) {
    	return;
    }
    
    if (node->key >= min && node->key <= max) {
        count += node->key;
    }

    if (node->key >= min)  
    	sumRangeHelper(node->left, count, min, max);

    if (node->key <= max)
    	sumRangeHelper(node->right, count, min, max);

}

float sumRange(int min, int max) {

    float count = 0; 
    sumRangeHelper(root, count, min, max); 
    return count;
}

int main(int argc, char ** argv) {
    
    root = new BSTNode(7);	

    root->left = new BSTNode(5);
    root->right = new BSTNode(10);

    root->left->left = new BSTNode(3);
    root->left->right = new BSTNode(6);

    root->right->left = new BSTNode(8);
    root->right->right = new BSTNode(12);

    root->right->left->left = new BSTNode(7.5);

    cout << sumRange(6,11) << endl;
	
}
