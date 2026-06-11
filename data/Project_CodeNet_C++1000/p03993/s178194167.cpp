#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll N = 0,M = 0,count = 0;
  cin >> N;
  vector<int>A(N);
  rep(i,N){
    cin >> A[i];
  }
  rep(i,N){
    M = A[i];
    if(i == A[M - 1] - 1 && M == A[i]){
      count++;
    }
  }
    cout << count / 2;
}