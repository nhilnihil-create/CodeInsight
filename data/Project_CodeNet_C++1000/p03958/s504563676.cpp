#include<iostream>
#include<functional>
#include<vector>
#include<vector>
#include<utility>
#include<cmath>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
using ll =long long;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(i) i.begin(),i.end()
template<typename T=ll>
using v =vector<T>;
template<typename T=ll>
using vv = vector<v<T>>;
template<typename T=ll,typename U=ll> using p = pair<T,U>;
const ll INF = (ll)1e9;
const ll MOD = INF+7;
template<typename T> T chmin(T &a,T b){a=min(a,b);}
template<typename T> T chmax(T &a,T b){a=max(a,b);}

void b(){
    ll k,t;
    cin >> k >> t;
    v<> a(t,0LL);
    rep(i,t){
        cin >> a[i];
    }
	
    sort(a.begin(),a.end());
    while(1){
        auto it = upper_bound(a.begin(),a.end(),0LL);
        if(it==a.end()-1)break;
      	if(it==a.end()) break;
        a[t-1] -=*it;
        *it=0;
        sort(a.begin(),a.end());
    }
    cout << max(0LL,a[t-1]-1) <<endl;

}

int main(){
    b();
}