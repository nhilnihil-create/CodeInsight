#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
using vs = vector<string>;
using vb = vector<bool>;
using vll = vector<long long>;
using vpii = vector<pair<int,int>>;
using vivi = vector<vector<int>>;
using vbvb = vector<vector<bool>>;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
const int mod = 1000000007;
const int inf = 1001001001;



int main(void) {
  int n;
  cin >> n;
  vi a(n);
  rep(i,n) cin >> a[i];
  int forc = 0;
  int twoc = 0;
  
  rep(i,n){
    if(!(a[i]%4))forc++;
    else if(!(a[i]%2))twoc++;
  }
  int kisu = n - forc - twoc;
  //cout << twoc << " " << forc << " " << kisu << endl;
  if(min(1,twoc)+kisu<=forc+1) cout << "Yes" << endl;
  else cout << "No" << endl;
}


