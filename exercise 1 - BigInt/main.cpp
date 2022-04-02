#include "BigInt.cpp"

int main(){
    //RandomBigInt(20000, 10000, "data.inp");
    BigInt bi1, bi2;
    Input("data.inp", bi1, bi2);
    Output(bi1);  
    cout << endl; 
    Output(bi2);
    cout << endl;
    return 0;
}