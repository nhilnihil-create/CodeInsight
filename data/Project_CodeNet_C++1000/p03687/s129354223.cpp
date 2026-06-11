#include<bits/stdc++.h>
using namespace std;
using ll =long long;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(i) i.begin(),i.end()
template<typename T=ll>
using v =vector<T>;
template<typename T=ll> using vv = vector<v<T>>;
template<typename T=ll,typename U=ll> using p = pair<T,U>;
const ll INF = (ll)1e9;
template<typename T> T chmin(T &a,T b){a=min(a,b);}
template<typename T> T chmax(T &a,T b){a=max(a,b);}

ll f(string s,char c){
    bool k =true;
    rep(i,s.size()) if(s[i]!=c)k=false;
    if(k) return 0;
    string t(s.size()-1,'.');
    rep(i,s.size()-1){
        if(s[i]==c||s[i+1]==c)t[i]=c;
        else t[i]=s[i];
    } 
    return f(t,c)+1;
}

int main(){
    string t;
    cin >> t;
    ll _min =INF;
    for(char c='a';c<='z';c++){
        chmin(_min,f(t,c));
    }
    cout << _min << endl;
    return 0;
}