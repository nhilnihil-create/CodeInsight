#include <bits/stdc++.h>
using namespace std;

#define NDEBUG
#ifdef DEBUG
#include "../cout11.h"
#undef NDEBUG
#endif
#include <cassert>

typedef long long ll;
typedef long double Double;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef pair<double,double> dd;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long double> vD;

#define sz(a)  int((a).size())
#define pb  push_back
#define FOR(var,from,to) for(int var=(from);var<=(to);++var)
#define rep(var,n)  for(int var=0;var<(n);++var)
#define rep1(var,n)  for(int var=1;var<=(n);++var)
#define repC2(vari,varj,n)  for(int vari=0;vari<(n)-1;++vari)for(int varj=vari+1;varj<(n);++varj)
#define ALL(c)  (c).begin(),(c).end()
#define RALL(c)  (c).rbegin(),(c).rend()
#define tr(i,c)  for(auto i=(c).begin(); i!=(c).end(); ++i)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define mid(x,y) ((x)+((y)-(x))/2)
#define IN(x,a,b) ((a)<=(x)&&(x)<=(b))
#define cons make_pair


ll without_ijl(ll i, ll j, ll l) {
    i /= 2; j /= 2; l /= 2;
    return 2*i + 2*j + 2*l;
}
ll with_ijl(ll i, ll j, ll l) {
    if (i && j && l) {
        return 3 + without_ijl(i-1, j-1, l-1);
    } else {
        return 0;
    }
}
ll solve(vi& a) {
    ll I = a[0], O = a[1], J = a[3], L = a[4];
    return O + max(with_ijl(I,J,L), without_ijl(I,J,L));
}

int main() {
    vi a(7);
    rep(i,7) cin >> a[i];
    cout << solve(a) << endl;
    return 0;
}
