#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <cmath>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int mod=1e9+7;

int main() {
 int N,M;
 cin>>N>>M;
 if(abs(N-M)>=2){cout<<0<<endl;}
 else{
    int64_t r=1,l=1;
    for(int i=1;i<=N;i++){
      (r*=i)%=mod;
    }
    for(int i=1;i<=M;i++){
      (l*=i)%=mod;
    }
    if(abs(N-M)==0){
      cout<<2*r*l%mod<<endl;
    }
    else{cout<<r*l%mod<<endl;}
 }
 return 0;  
}