#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

ll cmb(ll x, ll y){
    if(y>x||y<0) return 0LL;
    ll c = 1;
    for(ll i = 0LL; i < y; i++) {
        c*=x-i;
      	c/=i+1;
    }
    return c;
}

int main() {
    ll N,A,B;
    cin>>N>>A>>B;
    vector<ll> v(N);
    map<ll,ll> m;
    for(int i = 0; i < N; i++) {
        cin>>v[i];
        m[v[i]]++;
    }
    sort(v.begin(),v.end());
    ll ans = 0LL;
    ll cnt = 0LL;;
    ll s = 0LL;
    for(ll i = 0; i < A; i++) {
        ans+=v[N-1-i];
        if(v[N-1-i]==v[N-A]) s++;
    }
  	if(v[N-1]==v[N-A]){
    	for(ll i = s; i <= min(m[v[N-A]],s+B-A);i++){
      		cnt+=cmb(m[v[N-A]],i);
    	}
    }
  	else cnt = cmb(m[v[N-A]],s);
    double t = (double)ans/A;
    cout<<fixed<<setprecision(10)<<t<<endl;
    cout<<cnt<<endl;
}