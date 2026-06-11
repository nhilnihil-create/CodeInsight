#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll N = 0,ans = 0;
  cin >> N;
  vector<ll>A(N);
  rep(i,N){
    cin >> A[i];
    ans += A[i];
  }
  sort(A.begin(), A.end()); //小さい順
  bool a = false;
  rep(i,N){
    if(A[i] % 10 != 0){
      a = true;
    }
  }
  if(!a){
    cout << "0";
  }
  else{
    if(ans % 10 != 0){
      cout << ans;
      return 0;
    }
    else{
      rep(i,N){
        if(A[i] % 10 != 0){
          cout << ans - A[i];
          return 0;
        }
      }
    }
  }
}
    