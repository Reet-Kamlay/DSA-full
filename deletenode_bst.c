struct Node *inOrderProcessor(struct Node *root){
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
struct Node *deletnode(struct Node *root,int value){
    struct Node *iPre;
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL:
    }
    if(value<root->data){
        root->left=deletnode(root->left,value);
    }
    else if(value>root->data){
        root->right=deletnode(root->right,value);
    }
    else{
        iPre=inOrderProcessor(root);
        root->data=iPre->data;
        root->left=deletnode(root->left,iPre->data);
    }
    return root;
}