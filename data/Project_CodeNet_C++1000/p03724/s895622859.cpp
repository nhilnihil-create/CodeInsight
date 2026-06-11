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
  int n, m;
  cin >> n >> m;
  vl vec(n, 0);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    vec[a]++; vec[b]--;
  }
  bool allEven = true;
  int sum = 0;
  rep(i, n-1){
    sum += vec[i];
    if(sum%2==1) allEven = false;
  }
  if(allEven) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}