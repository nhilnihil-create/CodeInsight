#include<bits/stdc++.h>
#define rep(m, n) for (int m = 0; m < (n); ++m) 
#define PI acos(-1)
#define pcnt __builtin_popcountll
#define rng(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define v(T) vector<T>
#define vv(T) v(v(T))
#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

template<typename T>inline istream& operator>>(istream&m,v(T)&v)
{rep(j,sz(v))m>>v[j];return m;}
template<typename T1,typename T2>inline istream& operator>>(istream&m,pair<T1,T2>&v)
{return m>>v.fi>>v.se;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false; }

ll INF = 1001001001;
ll LINF = 1001001001001001001ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, l;
    cin>>n>>l;
    vl as(n);
    cin>>as;

    ll ans = -1;
    rep(i, n - 1) {
        if (as[i] + as[i + 1] >= l) {
            ans = i + 1;
            break;
        }
    }
    if (ans == -1) {
        cout<<"Impossible"<<endl;
        return 0;
    }
    cout<<"Possible"<<endl;
    int m = 1;
    while (m < ans) {
        cout<<m<<endl;
        m++;
    }
    m = n - 1;
    while (ans <= m) {
        cout<<m<<endl;
        m--;
    }
}