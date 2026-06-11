#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main(){
    
    long long A,B,C;
    
    cin >> A >> B >> C;
    
    if(B < C)swap(B,C);
    if(A < B)swap(A,B);
    if(B < C)swap(B,C);
    
    cout << (A*B*C - (B*C)*(A/2)) - (B*C)*(A/2)<<endl;
    
}
    
    

