#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K,X,Y;
    cin>>N>>K>>X>>Y;
    int A;
    A = K*X;
    int B;
    B = (N-K)*Y;
    if(N<=K){
        A=N*X;
        B=0;
    }
    cout<<A+B<<endl;
}
