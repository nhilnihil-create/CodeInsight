#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define REP(i,j,n) for(int i = j;i < (n);i++)
#define intput(i) cout << i << endl
#define ll long long
#define stringput(s) cout << (string)(s) << endl


int main(){
  ll N, M, K;
  cin >> N >> M >> K;
  string ans = "No";
  rep(i,N+1){
    rep(j,M+1){
      ll cnt = i*M + j*N - 2*i*j;
      if(cnt == K){
        ans = "Yes";
        break;
      }
    }
  }
  cout << ans << endl;
}
