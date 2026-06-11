#include <bits/stdc++.h>
#include<queue>
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef pair<string,string> Pstring;
typedef pair<double,double> Pdouble;

#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define Precision13 cout << fixed << setprecision(13)
const double PI=3.14159265358979323846;
const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];
char maze[310][310];
ll ans[310][310];
int main() {

  string s;
  cin >> s;
  ll k;
  cin >> k;

  REP(i,s.size()){
    ll di = 'z'-s.at(i)+1;
    if(s.at(i)=='a'){
      continue;
    }
    if(k>=di){
      s.at(i) = 'a';
      k -= di;
    }
  }

  k %= 26;
  ll dl = 'z'- s.at(s.size()-1)+1;
  if(k>=dl){
    s.at(s.size()-1)='a'+k-dl;
  }else{
    s.at(s.size()-1)= s.at(s.size()-1)+k; 
  }
  cout << s << endl;
}