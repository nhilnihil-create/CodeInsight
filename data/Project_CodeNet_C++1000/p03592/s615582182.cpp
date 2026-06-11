#include <bits/stdc++.h>
using namespace std; 
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

//    M
//  --^^^
//N --^^^
//  ^^---

int main(){
  int N; cin >> N;
  int M,K; cin >> M >> K;
  bool flag = false;
  REP(i,N+1){
    REP(j,M+1){
      if( (N-i)*j + i*(M-j) == K){
        flag = true;
        break;
      }
    }
  }
  cout << (flag? "Yes\n":"No\n");
}