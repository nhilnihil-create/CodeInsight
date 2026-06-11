#include<bits/stdc++.h>
using namespace std;
#define REP(i,N) for(int (i)=0;(i)<(N);(i)++)
#define REPR(i,N) for(int (i)=(N);i>=0;i--)
#define FOR (i,m,n) for(int (i)=m;(i)<(n);(i)++)

int main(){
  int num, K, termx, ans=0;
  cin >> num >> K;
  REP(i,num){
    cin >> termx;
    if(termx<K-termx)ans+=2*termx;
    else ans+=(K-termx)*2;
  }
  cout << ans;
}