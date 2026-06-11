#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rrep(i,n) for(ll i=(n)-1;i>=0;i--)
template<typename T =ll> using v = vector<T>;
template<typename T =ll> using vv = v<v<ll>>;
template<typename T=ll,typename U=ll> using p = pair<T,U>;
template<typename T> T chmin(T &a,T b) {return a=min(a,b);}
template<typename T> T chmax(T &a,T b) {return a=max(a,b);}
const ll INF = (ll)1e9;

void a(){
    ll N,A,B;
    cin >> N >> A >> B;
    if(A<B&&N>1){
        ll sum = (N-2)*(B-A)+1;
        cout << sum << endl;
    }else if(A==B){
        cout << 1 << endl;
    }else{
        cout << 0 << endl;
    }
}

void b(){
    string s;
    cin >> s;
    ll c=0;
    rep(i,s.size()-1){
        if(s[i]!=s[i+1]) c++;
    }
    cout << ((ll)s.size())*((ll)s.size()-1) +c;
}

int main(){
    a();
}