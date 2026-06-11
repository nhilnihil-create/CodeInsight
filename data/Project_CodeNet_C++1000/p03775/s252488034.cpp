#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define ll long long
#define rep(i,n) for (int i = 0; i < (n); i++)
int cnt_digits(ll N){
 int digits=0;

 while(N>0){
 N/=10;
 digits++;
 }

 return digits;
 }
int main() {
  ll N;
  cin >> N;
  int ans=1e9;
  int cnt=0;
  int temp=0;
  for(ll i=1;i*i<=N;i++){
    if((N)%i==0){
      temp=max(cnt_digits(i),cnt_digits((N/i)));
      ans=min(ans,temp);
    }

  }
  cout << ans << endl;
}
