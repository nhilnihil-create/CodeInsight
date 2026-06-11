#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define cvector vector<char>
#define svector vector<string>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define rep(i,n) for(ll i=0; i<n; ++i)
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,m,a,b;cin>>n>>m;
  lvector v(n,0);
  rep(i,m) {
    cin>>a>>b;a--,b--;
    v[a]++,v[b]++;
  }
  bool isok=true;
  for(ll i:v) if(i%2==1) isok=false;
  print(isok?"YES":"NO");
  return 0;
}