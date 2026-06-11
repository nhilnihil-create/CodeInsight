#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define ios ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0)
#define so sizeof
#define pb push_back
#define cl clear() ;
#define vl vector<ll>
#define sz size()
#define len length()
#define el endl;cout.flush()
#define be begin()
#define fi first
#define se second
#define br break
#define en end()
#define ro return 0
#define br break
#define eb emplace_back
#define con continue
#define ms(x) memset(x , 0, so x)
#define all(x) (x).be , (x).en
#define acc(x) accumulate((x).be , (x).en , 0ll)
#define forn(i,a,b) for(ll i=a;i<=b;++i)
#define rng_58 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define plll pair<ll,pair<ll,ll>>
#define plvl pair<pair<ll,ll> ,ll>
#define mp make_pair
#define trace3(a,b,c) cerr <<"a is " << a << " b is " << b << " c is " << c << el;
#define trace4(a,b,c,d) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << el ;
#define trace5(a,b,c,d,e) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << " e is " << e << el;
#define trace6(a,b,c,d,e,f) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << " e is " << e << " f is " << f << el ;
vector<ll> v[200005] , vv[200005] ;
ll visited[200005] , a[200005] , b[200005];
void dfs(ll curr , ll nos)
{
    visited[curr] = 1 ;
    a[curr] = nos ;
    for(auto &x : v[curr]){
        if(visited[x] == 0){
            dfs(x, nos);
        }
    }
}
void dfss(ll curr , ll nos)
{
    visited[curr] = 1;
    b[curr] = nos;
    for(auto &x : vv[curr]){
        if(visited[x] == 0 ){
            dfss(x, nos) ;
        }
    }
}
int main()
{
    ios;
    ll n , k , l ;
    cin >> n >> k >> l ;
    forn(i , 1 , k ) {
       ll x , y ;
       cin >> x >> y;
       v[x].pb(y) ;
       v[y].pb(x) ;
    }
    forn(i , 1 , l ) {
       ll x , y ;
       cin >> x >>  y;
       vv[x].pb(y) ;
       vv[y].pb(x) ;
    }
    ll ccr = 0 , ccl = 0 ;
    forn(i , 1 , n ) {
       if(visited[i] == 0 ) {
            ++ccr;
           dfs(i , ccr);
       }
    }
    ms(visited) ;
    forn(i , 1 , n ) {
       if(visited[i] == 0){
        ++ccl;
        dfss(i , ccl) ;
       }
    }
    map< pair<ll , ll > , ll > mpp ;
    forn(i , 1 , n ) {
       pll foo = {a[i] , b[i]} ;
       mpp[foo]++;
    }
    vl ans ;
    forn(i , 1 , n ) {
       pll curr = {a[i] , b[i] } ;
       ll tot = mpp[curr] ;
       ans.pb(tot) ;
    }
    for(auto &x : ans) cout << x << " " ;
    cout << el ;
}
