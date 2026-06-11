#include <bits/stdc++.h>
using namespace std; 
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

int main(){
  int N; cin >>N;
  N *= 2;
  int L[N];
  REP(i,N){
    cin >> L[i];
  }
  sort(L,L+N,greater<int>());
  
  int r = 0;
  for(int i=1;i<N;i+=2){
    r += L[i];
  }
  cout << r << '\n';
}
  