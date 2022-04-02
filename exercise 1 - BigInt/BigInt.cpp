#include "BigInt.h"

Node *GetNode(int x){
    Node *p = new Node;
    if (p == NULL)
        return NULL;
    p->info = x;
    p->pNext = NULL;
    p->pPrev = NULL;
    return p;
}

void Init(BigInt &bi){
    bi.pHead = bi.pTail = NULL;
}

void AddTail(BigInt &bi, Node *p){
    if (bi.pHead == NULL)
        bi.pHead = bi.pTail = p;
    else{
        bi.pTail->pNext = p;
        p->pPrev = bi.pTail;
        bi.pTail = p;
    }
}

void Input(const char* filename, BigInt &bi1, BigInt &bi2){
    Init(bi1);
    Init(bi2);
    ifstream ifs(filename);
    ifs.unsetf(ios_base::skipws);
    char c;
    while (ifs >> c && c != '\n'){
        int x = c - 48;
        Node *p = GetNode(x);
        AddTail(bi1, p);
    }

    while (ifs >> c){
        int x = c - 48;
        Node *p = GetNode(x);
        AddTail(bi2, p);
    }
    ifs.close();
}

void RandomBigInt(int n, int m, const char* filename){
    srand((unsigned)time(NULL));
    ofstream ofs(filename);
    for (int i=1; i<=n; i++){
        int info = rand() % 10;
        ofs << info;
    }
    ofs << '\n';
    for (int i=1; i<=m; i++){
        int info = rand() % 10;
        ofs << info;
    }
    ofs.close();
}

void Output(BigInt bi){
    Node *p = bi.pHead;
    while (p != NULL){
        cout << p->info;
        p = p->pNext;
    }
}

BigInt Add(BigInt bi1, BigInt bi2){

}

BigInt Minus(BigInt bi1, BigInt bi2);
BigInt Multiply(BigInt bi1, BigInt bi2);

