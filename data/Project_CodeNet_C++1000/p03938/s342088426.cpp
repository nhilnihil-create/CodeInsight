#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<'\n';
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<ll> p(n+1);
    FOR(i,1,n+1) cin>>p[i];
    vector<ll> x(n+1);
    FOR(i,1,n+1) x[p[i]]=i;
    vector<ll> a(n+1),b(n+1);
    FOR(i,1,n+1){
      a[i]=30000*i;
      b[i]=30000*(n-i)+x[i];
    }
    FOR(i,1,n+1){
      cout<<a[i]<<' ';
    }
    cout<<endl;
    FOR(i,1,n+1){
      cout<<b[i]<<' ';
    }
    cout<<endl;
}