//
// Created by Yeonwoo Kim on 2023/12/10.
//
#include <stdio.h>
#include <string.h>
#include <malloc/_malloc.h>

typedef struct NODE {
    char *pszData;

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
}

void ReleaseList(void) {

}

void PrintList(void) {

}

int InsertAtHead(const char *pszData) {
    return 0;
}

int InsertAtTail(const char *pszData) {
    return 0;
}

NODE *FindNode(const char *pszData) {
    return NULL;
}

int DeleteNode(const char *pszData) {
    NODE *pNode = FindNode(pszData);
    return 0;
}

int GetSize(void) {
    return g_nSize;
}

int GetLength(void) {
    return GetSize();
}


int main(void) {
    return 0;
}
