#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define REP(i, n) for (LL i = 0; i < (LL)(n); i++)
#define FOR(i, m, n) for (LL i = m; i < n; i++)
#define SORT(x) sort(x.begin(), x.end())
#define REVE(x) reverse(x.begin(), x.end())
#define ALL(x) (x).begin(), (x).end()
#define SUM(x) accumulate(x.begin(), x.end(),0)
#define vLL(v,n) vector<LL> v(n); REP(i,n)cin>>v[i];
#define vstr(v,n) vector<string> v(n); REP(i,n)REP(i,n)cin>>v[i];
#define mina(a,b) a=min(a,b);
LL INF = 1e9 + 1;
LL MOD = 1e9+7;
  LL a,b,c,d,e,n,m,l,r,ans=1000;
string s,S,t;
int main() {
ios_base::sync_with_stdio(false);
  cin >>s;
  REP(i,s.size()){
      REP(j,s.size()){
              if(i!=j&&s[i]==s[j]){
                  cout << "no"<<endl;
                  return 0;
          }
      }
  }
  cout << "yes"<<endl;
}
