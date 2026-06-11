#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll= long long;
using namespace std;

ll F(ll A,ll B){
    ll cntA=0,cntB=0;
    while(A!=0){
        A/=10;
        cntA++;
    }
    while(B!=0){
        B/=10;
        cntB++;
    }
    return max(cntA,cntB);
}

int main(){
    ll N,A,B;
    cin>>N;
    ll minF=12;
    for(int i=1;i<=sqrt(N);i++){
        if(N%i==0){
            A=i;
            B=N/i;
        }
        else{
            continue;
        }
        minF=min(minF,F(A,B));
    }
    cout<<minF<<endl;
       
    }
    
    
  
 
 


