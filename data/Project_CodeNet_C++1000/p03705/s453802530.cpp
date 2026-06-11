#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main(){
  ll N = 0,A = 0,B = 0;
  cin >> N >> A >> B;
  if(N == 1 && A != B){
    cout << "0";
    return 0;
  }
  if(B < A){
    cout << "0";
    return 0;
  }
  cout << B * (N - 2) - A * (N - 2) + 1;
}