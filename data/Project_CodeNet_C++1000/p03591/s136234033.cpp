#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define rep(i,n) for(ll i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define MOD 1000000007 //998244353
typedef vector<ll> vl;
typedef vector<vl> matrix;//A(n, vl(m)); //n*m行列
typedef vector<string> vs;
typedef pair<ll,ll> pl;
typedef vector<pl> vp;
typedef vector<bool> vb;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define Sortup(V) sort(V.begin(), V.end())
#define Sortdown(V) sort(V.rbegin(), V.rend())
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(b<a){a=b;return 1;}return 0;}
void CumuSum(vl &A){rep(i,A.size())if(i)A[i]+=A[i-1];}
ll llpow(ll e,ll x){ll res=1LL;while(x){if(x&1)res*=e;e*=e;x/=2;}return res;}
ll llpowMOD(ll e,ll x){ll res=1LL;while(x){if(x&1)res*=e;e*=e;x/=2;res%=MOD;e%=MOD;}return res;}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // solution comes here

    string S;
    cin >> S;
    if("YAKI" == S.substr(0, 4)) cout << "Yes" << nl;
    else                         cout << "No" << nl;
}