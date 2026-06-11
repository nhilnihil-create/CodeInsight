#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end());
#define vecmin(A) *min_element(A.begin(),A.end());
#define vecmax(A) *max_element(A.begin(),A.end());
typedef long long ll;

int main(){
  int n;
  cin >> n;
  string s1,s2;
  cin >> s1 >> s2;
  string ds = "";
  rep(i,n){
    if(s1[i] == s2[i]) ds.push_back('s');
    if(s1[i] != s2[i]){
      ds.push_back('d');
      i ++;
    }
  }
  int m = ds.size();
  ll ans = 1;
  rep(i,m){
    if(i == 0){
      if(ds[i] == 'd') ans = 6;
      if(ds[i] == 's') ans = 3;
    }
    if(i > 0){
      if(ds[i-1] == 's' && ds[i] == 'd'){
        ans *= 2;
        ans %= 1000000007;
      }
      if(ds[i-1] == 'd' && ds[i] == 'd'){
        ans *= 3;
        ans %= 1000000007;
      }
      if(ds[i-1] == 's' && ds[i] == 's'){
        ans *= 2;
        ans %= 1000000007;
      }
    }
  }
  cout << ans << endl;
}