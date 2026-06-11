#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define pa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};

using ll = long long;
using namespace std;
using P = pair<int,int>;
ll mod=1e9+7;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a; } //最大公約数
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; } //最大公倍数

int main(){
  int H,W,A[10000],N;
  cin>>H>>W;
  cin>>N;
  int ans[100][100] = {0};
  for (int i(0);i<N;i++){
    cin>>A[i];
  }
  int tmp(0);
  for (int i(0);i<H;i++){
    for (int j(0);j<W;j++){
      if (A[tmp] == 0){
        tmp += 1;
      }
      ans[i][j] = tmp+1;
      A[tmp]--;
    }
  }
  for (int i(0);i<H;i++){
    if (i%2==1){
      for (int j(0);j<W;j++){
        cout << ans[i][W-j-1] << " ";
      }
    }else{
      for (int j(0);j<W;j++){
        cout << ans[i][j] << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
