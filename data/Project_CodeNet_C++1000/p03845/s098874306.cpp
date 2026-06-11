#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long int i = 0; i < (long long int)(n); i++)
#define ll long long
#define ld long double

int main(){
  int n; cin >> n;
  vector<int> t(n); rep(i,n) cin >> t[i];
  int m; cin >> m;
  
  rep(i,m){
    vector<int> tmp(n); copy(t.begin(),t.end(),tmp.begin());
    int p,x; cin >> p >> x;
    tmp[p-1] = x;
    int sum = accumulate(tmp.begin(),tmp.end(),0);
    cout << sum << endl;
  }
}