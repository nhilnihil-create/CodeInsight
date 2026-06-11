#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    ll N;
    cin >> N;
    vector<ll> a(N),b(N);
    rep(i,N){
        a[i]=N*i+1;
        b[N-1-i]=N*i+1;
    }
    rep(i,N){
        ll p;
        cin >> p;
        p--;
        a[p]+=i;
        b[p]+=i;
    }
    rep(i,N){
        cout << a[i];
        if (i!=N-1){
            cout << ' ';
        }
        else {
            cout << endl;
        }
    }
    rep(i,N){
        cout << b[i];
        if (i!=N-1){
            cout << ' ';
        }
        else {
            cout << endl;
        }
    }
}