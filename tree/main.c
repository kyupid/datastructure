//
// Created by Yeonwoo Kim on 2023/12/10.
//
#include <stdio.h>
#include <string.h>
#include <malloc/_malloc.h>

typedef struct NODE {
    int data;
    int index;

    struct NODE *left;
    struct NODE *right;
} NODE;

NODE *g_pRoot;
int g_nSize;

void ReleaseTree(NODE *pParent) {
    if (pParent == NULL) {
        return;
    }

    ReleaseTree(pParent->left);
    ReleaseTree(pParent->right);

    printf("free(): %p, %d\n", pParent, pParent->data);
    free(pParent);
    g_pRoot = NULL;
}

void PrintTree(NODE *pParent) {
    if (pParent == NULL) {
        return;
    }
    PrintTree(pParent->left);

    printf("[%p] %p, %d [%p]\n", pParent->left, pParent, pParent->data, pParent->right);

    PrintTree(pParent->right);
}

int InsertNode(int data) {
    NODE *pNewNode = (NODE *) malloc(sizeof(NODE));
    memset(pNewNode, 0, sizeof(NODE));
    pNewNode->data = data;

    g_nSize++;

    if (g_pRoot == NULL) {
        g_pRoot = pNewNode;
        return 1;
    }

    NODE *pTmp = g_pRoot;
    while (pTmp != NULL) {
        //비교
        if (pTmp->data > pNewNode->data) {
            //left
            if (pTmp->left == NULL) {
                pTmp->left = pNewNode;
                break;
            } else {
                pTmp = pTmp->left;
                continue;
            }
        } else {
            //right
            if (pTmp->right == NULL) {
                pTmp->right = pNewNode;
                break;
            } else {
                pTmp = pTmp->right;
                continue;
            }
        }
    }

    return 1;
}

NODE *FindNode(int data) {
    return NULL;
}

NODE *FindMin(NODE *root) {
    if (root->left != NULL) {
        return FindMin(root->left);
    }
    return root;
}

NODE *DeleteNode(NODE *root, int data) {
    if (root == NULL) {
        return root;
    }
    if (root->data < data) {
        root->right = DeleteNode(root->right, data);
    } else if (root->data > data) {
        root->left = DeleteNode(root->left, data);
    } else if (root->data == data) {
        // case 1: no child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;

            // case2: one child
        } else if (root->left == NULL) {
            NODE *temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            NODE *temp = root;
            root = root->left;
            free(temp);

            // case3: two children
        } else if (root->left != NULL && root->right != NULL) {
            NODE *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = DeleteNode(root->right, temp->data);
        }
    }
    return root;
}

int GetSize(void) {
    return g_nSize;
}

int IsEmpty(void) {
    return GetSize();
}

int main(void) {
    InsertNode(7);
    InsertNode(5);
    InsertNode(3);
    InsertNode(6);
    InsertNode(10);
    InsertNode(8);
    InsertNode(12);
    InsertNode(13);

    PrintTree(g_pRoot);

    ReleaseTree(g_pRoot);
    return 0;
}
