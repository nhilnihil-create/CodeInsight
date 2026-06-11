#include <bits/stdc++.h>
using namespace std;

long long A, B, C;
int solve(){
    for(int i = 0;i< 1000000; ++i){
        if(A&1||B&1 ||C&1) return i;
        long long tA = (B+C)/2;
        long long tB = (A+C)/2;
        long long tC = (A+B)/2;
        
        A=tA,B=tB,C=tC;
    }
    return -1;
    
}
int main(void){
    cin>>A>>B>>C;
    cout<<solve()<<endl;
}
