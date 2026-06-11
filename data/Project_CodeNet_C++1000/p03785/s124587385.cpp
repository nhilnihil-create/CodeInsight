#include <bits/stdc++.h>
using namespace std;
typedef bool boool;
typedef long long ll;
#define vl vector<ll>
#define vb vector<boool>
#define vs vector<string>
#define vp vector<pair<ll, ll>>
#define vvl vector<vector<ll>>
#define vvp vector<vector<pair<ll, ll>>>
#define mod 1000000007
#define all(x) x.begin(), x.end()
#define rep1(i, n) for (long long i=0; i<(long long)(n); i++)
#define rep2(i, s, e) for (long long i=(s); i<(long long)(e); i++)
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)

int main(){
  int n, c, k;
  cin >> n >> c >> k;
  vl vec(n);
  rep(i, n) cin >> vec[i];
  sort(all(vec));
  int earliest = vec[0];
  int cnt = 1;
  int ans = 0;
  rep(i, 1, n){
    if(cnt == c){
      ans++;
      cnt = 1;
      earliest = vec[i];
    }else{
      if(earliest+k>=vec[i]){
      	cnt++;
      }else{
        ans++;
        cnt = 1;
        earliest = vec[i];
      }
    }
  }
  ans++;
  cout << ans << endl;
  return 0;
}
      
