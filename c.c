#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct  ListNode* next;
};

typedef struct {
    struct ListNode* head;
    struct ListNode* tail;
    int capacity; // ������
    int size;   // ��ǰ���ݸ���
} MyCircularQueue;

bool myCircularQueueIsFull(MyCircularQueue* obj);// ���溯��������
bool myCircularQueueIsEmpty(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->head = obj->tail = NULL;
    obj->capacity = k;
    obj->size = 0;

    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
    {
        return false;
    }
    else
    {
        struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val = value;
        newnode->next = NULL;
        if (obj->head == NULL)
        {
            obj->head = obj->tail = newnode;
        }
        else
        {
            obj->tail->next = newnode;
            obj->tail = newnode;
        }
        obj->size++;
        return true;
    }
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return false;
    }
    else
    {
        struct ListNode* node = obj->head;// �ȱ���Ҫ�ͷŵĶ�ͷ
        obj->head = obj->head->next; //�ƶ�����ͷ����һ��
        obj->size--;
        free(node);// �ͷ��������Ķ�ͷ
        return true;
    }
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    return obj->head->val;
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    return obj->tail->val;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if (obj->size == 0)
        return true;
    else
        return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if (obj->size == obj->capacity)
        return true;
    else
        return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    // 1.
     struct ListNode* cur = obj->head->next;
     while (cur != obj->tail)
     {
     	struct ListNode* next = cur->next;
     	free(cur);
     	cur = next;
     }
     // 2.
    for (struct ListNode* cur = obj->head; cur;) {
        struct ListNode* node = cur;
        cur = cur->next;
        free(node);
    }
    free(obj);
}

