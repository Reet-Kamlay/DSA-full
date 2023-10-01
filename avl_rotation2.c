#include<stdio.h>
#include<stdlib.h>
struct Node{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};
int max(int a,int b){
    return a>b?a:b;
}
int getheight(struct Node *node){
    if(node==NULL){
        return 0;
    }
    return (node->left)-(node->right);
}
int getbalancedfactor(struct Node *node){
    if(node==NULL){
        return 0;
    }
    return getheight(node->left)-getheight(node->right);
}
struct Node *createnode(int key){
    struct Node *node=(struct Node *)malloc(sizeof(struct Node));
    node->data=key;
    node->left=NULL;
    node->right=NULL;
    node->height=1;
    return node;
}
struct Node *insert(struct Node *node,int key){
    if(node==NULL){
        return NULL;
    }
    if(key<node->key){
        node->left=insert(node->left,key);
    }
    else if(key>node->key){
        node->right=insert(node->right,key);
        return node;
    }
    node->height=1+max(getheight(node->left),getheight(node->right));
    int bf=getbalancedfactor(node);
    if(bf>1 && key<node->left->key){
        return rightrotate(node);
    }
    if(bf<-1 && key>node->right->key){
        return leftrotate(node);
    }
    if(bf>1 && key>node->left->key){
        node->left=leftrotate(node->left);
        return rightrotate(node);
    }
    if(bf<-1 && key<node->right->key){
        node->right=rightrotate(node->right);
        return leftrotate(node);
    }
    return node;
}