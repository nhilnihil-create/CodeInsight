#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  int N = 0;
  cin >> N;
  vector<int>A(N);
  rep(i,N){
    cin >> A[i];
  }
  if(N % 2 == 0){
    rep(i,N/2){
      cout << A[N-1-2*i] << " ";
    }
    rep(i,N/2){
      cout << A[2*i] << " ";
    }
  }
  else{
    rep(i,N/2+1){
      cout << A[N-1-2*i] << " ";
    }
    rep(i,N/2){
      cout << A[2*i+1] << " ";
    }
  }
}