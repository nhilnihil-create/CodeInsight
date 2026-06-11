#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0;i < (n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vl>;


int main(){
  string a,b,c; cin >> a >> b >> c;
  if(a[a.size()-1]==b[0]&&b[b.size()-1]==c[0]) cout << "YES" << endl;
  else cout << "NO" << endl;
}