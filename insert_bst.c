void insert(struct Node *root,int key){
    struct Node *prev=NULL;
    if(root!=NULL){
        prev=root;
        if(key==root->data){
            return;
        }
        else if(key<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    struct Node *new=createnode(key);
    if(key<prev->data){
        prev->left=new;
    }
    else{
        prev->right=new;
    }
}