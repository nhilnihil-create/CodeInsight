#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

typedef vector<unsigned int>vec;
typedef vector<vec> mat;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const double PI = acos(-1.0);
const double EPS = 1e-10;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,L,T;
    cin>>N>>L>>T;
    vector<ll> X(N),W(N);
    REP(i,N) cin>>X[i]>>W[i];
    vector<ll> tmp(N);
    REP(i,N){
        if(W[i]==1) tmp[i]=(X[i]+T)%L;
        else tmp[i] = ((X[i]-T)%L + L)%L;
    }
    VSORT(tmp);
    ll cnt=0;
    REP(i,N){
        if(W[i]==1) cnt -= (T - (L - X[i]) + L) / L;
        else cnt += (T - (X[i] + 1) + L) / L;
    }
    cnt = (cnt % N + N) % N;
    vector<ll> res(N);
    REP(i,N) res[(i+cnt)%N] = tmp[i];
    REP(i,N) cout<<res[i]<<endl;
}
