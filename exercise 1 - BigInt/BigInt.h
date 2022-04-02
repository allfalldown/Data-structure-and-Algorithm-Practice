#pragma once
#include <iostream>
#include <fstream>
#include <time.h>
#include <random>

using namespace std;

struct Node{
    int info;
    struct Node* pNext;
    struct Node* pPrev;
};

struct BigInt{
    Node *pHead;
    Node *pTail;
};

Node *GetNode(int x);
void Init(BigInt &bi);
void AddTail(BigInt &bi, Node *p);
void Input(const char* filename, BigInt &bi1, BigInt &bi2);
void RandomBigInt(int n, int m, const char* filename);
void Output(BigInt bi);
BigInt Add(BigInt bi1, BigInt bi2);
BigInt Minus(BigInt bi1, BigInt bi2);
BigInt Multiply(BigInt bi1, BigInt bi2);
