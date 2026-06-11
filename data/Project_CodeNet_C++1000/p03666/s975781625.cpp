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
  ll n,a,b,c,d;cin>>n>>a>>b>>c>>d;
  ll x=a-b,l,r;
  bool isok=false;
  rep(i,n) {
    l=i*c-(n-1-i)*d;
    r=i*d-(n-1-i)*c;
    if(l<=x&&x<=r) {isok=true;break;}
  }
  print(isok?"YES":"NO");
  return 0;
}