#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;


class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int value){
            data = value;
            right = left = NULL;
        }
};

// Create a new tree
static int idx = -1;
Node* buildTree(vector<int> preorderValues){
    idx++;

    if(preorderValues[idx] == -1) return NULL;
    Node* root = new Node(preorderValues[idx]);

    root->left = buildTree(preorderValues);
    root->right = buildTree(preorderValues);

    return root;
}

int max(int leftH, int rightH){
    if(leftH > rightH){
        return leftH;
    } else {
        return rightH;
    }
}


// Height Of a tree
int height(Node* root){
    int rightH, leftH;

    if(root == NULL) return 0;

    leftH = height(root->left);
    rightH = height(root->right);

    return max(leftH, rightH) + 1;
}


// Tree travel
void travesTree(Node* preorder){

    if(preorder == NULL) return;
    
    cout<<preorder->data<<" ";
    travesTree(preorder->left);
    travesTree(preorder->right);

}

// Total number of nodes in a tree
int nodeCount(Node* root){
    if(root == NULL) return 0;

    int leftCount = nodeCount(root->left);
    int rightCount = nodeCount(root->right);

    return leftCount + rightCount + 1;
}

// Total(Sum) of nodes in a tree
int nodeSum(Node* root){
    if(root == NULL) {
        return 0;
    }

    int leftSum = nodeSum(root->left);
    int rightSum = nodeSum(root->right);

    return leftSum + rightSum + root->data;
}

bool sameTrees(Node* root1, Node* root2){

    if(root1 == NULL || root2 == NULL){
        return root1 == root2;
    }

    bool isLeftSame = sameTrees(root1->left, root2->left);
    bool isRightSame = sameTrees(root1->right, root2->right);
    return isLeftSame && isRightSame && root1->data == root2->data;
}


bool isSubtree(Node* root, Node* subRoot){

    if(root == NULL || subRoot==NULL){
        return root == subRoot;
    }
    if(root->data == subRoot->data && sameTrees(root, subRoot))
        return true;
    // } else {
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    // }
}

int main(){
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    vector<int> values = { 3, 4, -1, -1, 5, -1, 6, -1, -1};

    Node* root = buildTree(preorder);
    idx = -1;
    Node* root2 = buildTree(values);

    travesTree(root);
    cout<<endl;
    travesTree(root2);

    cout<<endl<<height(root)<<endl;

    cout<<"Total number of node are: "<<nodeCount(root)<<endl;

    cout<<"Sum of all nodes: "<<nodeSum(root)<<endl;
    cout<<"Trees are: "<<sameTrees(root, root2)<<endl;
    cout<<"Sub Trees: "<<isSubtree(root, root2)<<endl;
    
    return 0;
}