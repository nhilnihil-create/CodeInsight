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
    vector<ll> A(N);
    ll sum=0;
    rep(i,N){
        cin >> A[i];
        sum+=A[i];
    }
    ll per=N*(N+1)/2;
    if (sum%per!=0){
        cout << "NO" << endl;
        return 0;
    }
    ll round=sum/per,c=0;
    rep(i,N){
        ll a=A[(i+1)%N]-A[i];
        if ((round-a)%N!=0||a>round){
            cout << "NO" << endl;
            return 0;
        }
        c+=(round-a)/N;
    }
    if (c==round){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}