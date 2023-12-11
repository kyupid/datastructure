//
// Created by Yeonwoo Kim on 2023/12/10.
//
#include <stdio.h>
#include <string.h>
#include <malloc/_malloc.h>

typedef struct NODE {
    char szData[64];
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

    printf("free(): %p, %s\n", pParent, pParent->szData);
    free(pParent);
    g_pRoot = NULL;
}

void PrintTree(NODE *pParent) {
    if (pParent == NULL) {
        return;
    }
    PrintTree(pParent->left);

    printf("[%p] %p, %s [%p]\n", pParent->left, pParent, pParent->szData, pParent->right);

    PrintTree(pParent->right);
}

int InsertNode(const char *pszData) {
    NODE *pNewNode = (NODE *) malloc(sizeof(NODE));
    memset(pNewNode, 0, sizeof(NODE));
    strcpy(pNewNode->szData, pszData);

    g_nSize++;

    if (g_pRoot == NULL) {
        g_pRoot = pNewNode;
        return 1;
    }

    NODE *pTmp = g_pRoot;
    while (pTmp != NULL) {
        //비교
        if (strcmp(pTmp->szData, pNewNode->szData) > 0) {
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

NODE *FindNode(const char *pszData) {
    return NULL;
}

int DeleteNode(const char *pszData) {
    return 0;
}

int GetSize(void) {
    return g_nSize;
}

int IsEmpty(void) {
    return GetSize();
}

int main(void) {
    InsertNode("5번 항목");
    InsertNode("4번 항목");
    InsertNode("7번 항목");
    InsertNode("6번 항목");
    InsertNode("8번 항목");

    PrintTree(g_pRoot);

    ReleaseTree(g_pRoot);
    return 0;
}
