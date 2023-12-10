//
// Created by Yeonwoo Kim on 2023/12/10.
//
#include <stdio.h>
#include <string.h>
#include <malloc/_malloc.h>

typedef struct NODE {
    char szData[64];
    int index;

    struct NODE *prev;
    struct NODE *next;
} NODE;

NODE *g_pHead;
NODE *g_pTail;
int g_nSize;

// 글로벌 변수들 초기화 해주는 역할
void InitList(void) {
    g_pHead = (NODE *) malloc(sizeof(NODE));
    g_pTail = (NODE *) malloc(sizeof(NODE));

    g_nSize = 0;
    memset(g_pHead, 0, sizeof(NODE));
    memset(g_pTail, 0, sizeof(NODE));

    strcpy(g_pHead->szData, "DUMMY HEAD");
    strcpy(g_pTail->szData, "DUMMY TAIL");

    g_pHead->next = g_pTail;
    g_pTail->prev = g_pHead;
}

void ReleaseList(void) {
    NODE *pTmp = g_pHead;
    while (pTmp != NULL) {
        NODE *pDelete = pTmp;
        pTmp = pTmp->next;

        printf("free(%p)\n", pDelete);
        free(pDelete);
    }
    g_pHead = NULL;
    g_pTail = NULL;
    g_nSize = 0;

    puts("ReleaseList()");
}

void PrintList(void) {
    printf("PrintList(): g_nSize: %d, g_phead [%p], g_Tail[%p]\n", g_nSize, g_pHead, g_pTail);
    NODE *pTmp = g_pHead;
    while (pTmp != NULL) {
        printf("[prev: %p] index: %d, addr: %p, data: %s [next: %p]\n", pTmp->prev, pTmp->index, pTmp, pTmp->szData,
               pTmp->next);
        pTmp = pTmp->next;
    }
}

int InsertAtHead(const char *pszData) {
    NODE *pNewNode = malloc(sizeof(NODE));
    memset(pNewNode, 0, sizeof(NODE));
    strcpy(pNewNode->szData, pszData);

    pNewNode->next = g_pHead->next;
    pNewNode->prev = g_pHead;
    pNewNode->index = 0;

    g_pHead->next = pNewNode;
    pNewNode->next->prev = pNewNode;

    NODE *pTmp = pNewNode->next;
    while (pTmp != g_pTail) {
        pTmp->index++;
        pTmp = pTmp->next;
    }

    return g_nSize++;
}

int InsertAtTail(const char *pszData) {
    NODE *pNewNode = malloc(sizeof(NODE));
    memset(pNewNode, 0, sizeof(NODE));
    strcpy(pNewNode->szData, pszData);

    pNewNode->next = g_pTail;
    pNewNode->prev = g_pTail->prev;
    pNewNode->index = g_nSize;

    g_pTail->prev = pNewNode;
    pNewNode->prev->next = pNewNode;

    return g_nSize++;
}

NODE *FindNode(const char *pszData) {
    NODE *pTmp = g_pHead->next;
    while (pTmp != g_pTail) {
        if (strcmp(pTmp->szData, pszData) == 0) {
            printf("FindNode(): [%p] %s\n", pTmp, pTmp->szData);
            return pTmp;
        }
        pTmp = pTmp->next;
    }
    printf("FindNode(): Not Found, %s\n", pszData);
    return NULL;
}

int DeleteNode(const char *pszData) {
    NODE *pNode = FindNode(pszData);

    pNode->prev->next = pNode->next;
    pNode->next->prev = pNode->prev;

    printf("DeleteNode(): [%p] %s\n", pNode, pNode->szData);
    NODE *pTmp = pNode;
    while (pTmp != g_pTail) {
        pTmp->index--;
        pTmp = pTmp->next;
    }
    free(pNode);
    return g_nSize--;
}

int GetSize(void) {
    return g_nSize;
}

int GetLength(void) {
    return GetSize();
}

int IsEmpty(void) {
    return GetSize();
}

NODE *GetAt(int idx) {
    NODE *pTmp = g_pHead->next;
    for (int i = 0; i <= idx; i++) {
        if (i == idx) {
            return pTmp;
        }
        pTmp = pTmp->next;
    }
    return NULL;
}

int InsertAt(int idx, char *pszData) {
    if (idx == 0) {
        return InsertAtHead(pszData);
    }
    if (idx == g_nSize - 1) {
        return InsertAtTail(pszData);
    }

    NODE *pNewNode = malloc(sizeof(NODE));
    memset(pNewNode, 0, sizeof(NODE));
    strcpy(pNewNode->szData, pszData);

    NODE *pGetNode = GetAt(idx);
    if (idx > 0) {
        pNewNode->prev = pGetNode->prev;
        pNewNode->next = pGetNode;
        pNewNode->index = pGetNode->index;

        pGetNode->prev = pNewNode;
        pNewNode->prev->next = pNewNode;

        NODE *pTmp = pGetNode;
        while (pTmp != g_pTail) {
            pTmp->index++;
            pTmp = pTmp->next;
        }
        return g_nSize++;
    }
    return 0;
}

int main(void) {
    InitList();
    InsertAtHead("TEST01");
    InsertAtHead("TEST02");
    InsertAtHead("TEST03");

    printf("GetAt(): [%p]\n", GetAt(0));
    printf("%d\n", g_nSize);
    int i = InsertAt(1, "TEST1111111111111");
    printf("%d\n", g_nSize);
//    GetAt(0);

//    PrintList();
//
//    FindNode("TEST01");
//    FindNode("TEST02");
//    FindNode("TEST03");
//    FindNode("TEST04");
//
//    DeleteNode("TEST02");
//
//    InsertAtHead("TEST07");
//    InsertAtHead("TEST08");
//    InsertAtHead("TEST09");

    PrintList();
    ReleaseList();
    return 0;
}
