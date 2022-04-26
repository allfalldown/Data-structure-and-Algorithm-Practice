#include "BigInt.cpp"

int main(){
    //RandomBigInt(20000, 10000, "data.inp");
    BigInt bi1, bi2;
    Input("data.inp", bi1, bi2);
    cout << "== Data infomation ==" << endl;
    display(bi1.pHead);
    display(bi2.pHead);

    Node *p = bi1.pHead;
    Node *q = bi2.pHead;
    //sum
    p = reverse(p);
    q = reverse(q);
    Node* sum = addTwoLists(p, q);
    sum = reverse(sum);
    cout << "== Sum ==" << endl;
    display(sum);

    //minus
    Node* sub = subtractLinkedList(p, q);
    cout << "== Minus ==" << endl;
    modify(p, q, sub);
    display(sub);

    //multify
    Node* mul = multiplyTwoLists(p, q);
    cout << "== Multify ==" << endl;
    display(mul);
    cout << endl;
    return 0;
}