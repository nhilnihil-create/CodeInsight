#include <bits/stdc++.h>
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<=int(b);i++)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define rrep(i,n) for (int i=(n-1);i >= 0;i--)
#define all(v) v.begin(),v.end()
#define sz(v) (int)((v).size())
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vl>;
template<class T>bool chmax(T &a, const T &b) {if(a<b){a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) {if(b<a){a=b; return 1;} return 0;}
const ll INF = 1LL << 60;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a,b,c;
    cin >> a >> b >> c;
    if(a==b+c||b==a+c||c==a+b) cout <<"Yes"<<endl;
    else cout << "No" << endl;
}
