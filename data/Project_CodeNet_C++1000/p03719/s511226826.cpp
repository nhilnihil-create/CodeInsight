#include <bits/stdc++.h>
using namespace std;

bool Check(int A, int B, int C){
    return (A <= C && C <= B);
}

int main(void){
    int A, B, C;
    cin >> A >> B >> C;
    
    if(Check(A,B,C) ) 
        cout << "Yes";
    else 
        cout << "No";
}
