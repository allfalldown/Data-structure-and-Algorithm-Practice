#pragma once
#include <iostream>
#include <fstream>
#include <time.h>
#include <random>

using namespace std;

struct Node{
    int data;
    Node *next;
};

struct BigInt{
    Node *pHead;
    Node *pTail;
};

//preprocess
Node* newNode(int data);
void AddTail(BigInt &bi, Node *p);
void push(Node** head_ref, int new_data);
void Init(BigInt &bi);
void Input(const char* filename, BigInt &bi1, BigInt &bi2);
void RandomBigInt(int n, int m, const char* filename);

//sum
Node* addTwoLists(Node* first, Node* second);
Node* reverse(Node* head);


//minus
int getLength(Node* Node);
Node* paddZeros(Node* sNode, int diff);
Node* subtractLinkedListHelper(Node* l1, Node* l2, bool& borrow);
Node* subtractLinkedList(Node* l1, Node* l2);
void modify(Node *l1, Node *l2, Node *res);
void display(Node* Node);

//multify
Node* make_empty_list(int size);
int reverse1(struct Node** head_ref);
Node* multiplyTwoLists(Node* first, Node* second);



