#include<iostream>
#include<queue>

using namespace std;

class Node{
    public:
        int d;
        Node * left;
        Node * right;

        Node(int d){
            this->d = d;
            this->left = NULL;
            this->right = NULL;                  
        }
};
Node* buildTree(Node* root){
        int data;
        cout<<"Enter the data "<<endl;
        cin>>data;
        root = new Node(data);

        if(data == -1){
            return NULL;
        }

        cout<<"Enter the data for inserting in left "<<data<<endl;
        root->left = buildTree(root->left);
        cout<<"Enter the data data inserting in right "<<data<<endl;
        root->right = buildTree(root->right);
        return root;
};

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        if(temp ==NULL){
            // previous level order complete
            cout<<endl;
            if(!q.empty()){
                //queue still has some child nodes
                q.push(NULL);
            }
        }
        else{
            cout<<temp->d<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
void inorder(Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->d<<" ";
    inorder(root->right);      
}
void preorder(Node *root){
    if(root == NULL){
        return;
    }
    cout<<root->d<<" ";   
    preorder(root->left);
    preorder(root->right);      
}
void postorder(Node *root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);   
     cout<<root->d<<" ";   
}

void buildFromLevelOrder(Node* &root){
    queue<Node*> q;
    cout<<"Enter data for root "<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout<<"Enter left node for "<<temp->d<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1){
            temp->left = new Node(leftdata);
            q.push(temp->left);
        }
        cout<<"Enter right node for "<<temp->d<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1){
            temp->right = new Node(rightdata);
            q.push(temp->right);
        }
    }
}
int main(){
    Node * root = NULL;
    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    return 0;
}