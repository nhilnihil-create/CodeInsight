#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int i, K, x;
  ll N, A, B, count, min=LLONG_MAX;
  
  cin >> N;
  
  for(A=1;A*A<N+1;A++){
    if(N%A==0){
      B=N/A;
      for(count=0;B>0;count++){
        B/=10;
      }
    }
    if(min>count) min=count;
  }
  
  cout << count;
}