#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int MAX = 510000;
ll dy[8] = {0,1,0,-1,1,-1,1,-1};
ll dx[8] = {1,0,-1,0,1,-1,-1,1};
const double pi = acos(-1);
const double eps = 1e-7;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){
	if(a>b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){
	if(a<b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << endl;}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << a << " " << b << " " << c << endl;
}
const int mod = 1e9 + 7;

int main(){
    string s,t; cin >> s >> t;
    ll n = s.size();
    ll m = t.size();
    vpl scnt(n+1,{0,0});
    vpl tcnt(n+1,{0,0});
    rep(i,n){
        scnt[i+1].first += scnt[i].first + (s[i]=='A');
        scnt[i+1].second += scnt[i].second + (s[i]=='B');
    }
    rep(i,m){
        tcnt[i+1].first += tcnt[i].first + (t[i]=='A');
        tcnt[i+1].second += tcnt[i].second + (t[i]=='B');
    }
    ll q; cin >> q;
    while(q--){
        ll a,b,c,d; cin >> a >> b >> c >> d;
        ll A = scnt[b].first-scnt[a-1].first-(tcnt[d].first-tcnt[c-1].first);
        ll B = scnt[b].second-scnt[a-1].second-(tcnt[d].second-tcnt[c-1].second);
        if(A<B) swap(A,B);
        if((A-B)%3==0) puts("YES");
        else puts("NO");
    }
}