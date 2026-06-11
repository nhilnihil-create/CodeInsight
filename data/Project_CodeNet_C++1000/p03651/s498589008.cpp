#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

ll gcd(ll m, ll n) {//最大公約数
    if (n == 0)return m;
    return gcd(n, m % n);
}//gcd

int main(){
  int n,k;
  cin>>n>>k;
  int ma=0;
  int p=0;
  rep(i,n){
    int a; cin>>a;
    ma=max(ma,a);
    p=gcd(a,p);
  }
  if(k%p==0 && k<=ma) cout<<"POSSIBLE"<<endl;
  else cout<<"IMPOSSIBLE"<<endl;
}
