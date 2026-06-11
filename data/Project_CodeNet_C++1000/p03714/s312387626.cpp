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
#define mod %
#define eb emplace_back
#define con continue
#define ms(x) memset(x , 0, so x)
#define all(x) (x).be , (x).en
#define rall(x) (x).rbegin() , (x).rend()
#define acc(x) accumulate((x).be , (x).en , 0ll)
#define forn(i,a,b) for(ll i=a;i<=b;++i)
#define rng_58 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define plll pair<ll,pair<ll,ll>>
#define plvl pair<pair<ll,ll> ,ll>
#define mp make_pair
#define trace2(a,b) cerr <<"a is " << a << " b is " << b << el;
#define trace3(a,b,c) cerr <<"a is " << a << " b is " << b << " c is " << c << el;
#define trace4(a,b,c,d) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << el ;
#define trace5(a,b,c,d,e) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << " e is " << e << el;
#define trace6(a,b,c,d,e,f) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << " e is " << e << " f is " << f << el ;
struct maxheap
{
    bool operator()(const pll &a , const pll &b)
    {return a.fi < b.fi ;}
};
struct minheap
{
    bool operator()(const pll &a , const pll &b)
    {return a.fi > b.fi ;}
};
struct minheapp
{
    bool operator()(const ll &a ,const ll &b) {
       return a < b ;
    }
};
struct op
{
    bool operator()(const ll &a , const ll &b) {
       return a > b;
    }
};
int main()
{
    ios ;
    ll n;
    cin >> n;
    vl v ;
    forn(i , 1 , 3*n){
      ll x;
      cin >> x;
      v.pb(x);
    }
     priority_queue<pll , vector<pll> , minheap > pq1 , ppq1 ;
     priority_queue<ll , vl , minheapp > nottaken , nt ;
     priority_queue<pll , vector<pll> , maxheap > pq2 , ppq2 ;
     ll pick[2*n+1] ;
     forn(i , n , 2*n - 1) pick[i] = -1;
     forn(i , 0 , n-1) pq1.push({v[i] , i});
     forn(i , n , 2*n-1) {
        if(pq1.top().first < v[i]){
            pick[pq1.top().se] = -1;
            pq1.pop();
            pq1.push({v[i],i});
            pick[i] = 1;
        }
     }
     forn(i , 0 , 2*n-1){
        if(pick[i] == -1){
            nottaken.push(v[i]);
        }
     }
     forn(i , 2*n , 3*n -1 ) {
        pq2.push({v[i] , i });
     }
     ppq1 = pq1 ; ppq2 = pq2 ;
     ll left = 0 , right = 0;
     multiset<ll > s1 ;
     while(!ppq1.empty()) {
       /// cout << ppq1.top().fi << " " ;
        s1.insert(ppq1.top().fi) ;
        left = left + ppq1.top().fi;
        ppq1.pop();
     }
    /// cout << el ;
     multiset<ll ,op> s2 ;
     while(!ppq2.empty()){
        ///cout<< ppq2.top().fi << " " ;
        s2.insert(ppq2.top().fi) ;
        right = right + ppq2.top().fi;
        ppq2.pop() ;
     }
     ///cout << el;
     nt = nottaken ;
     multiset<ll , op > s;
     while(!nt.empty()){
        ///cout << nt.top() << " " ;
        s.insert(nt.top());
        nt.pop();
     }
     ///cout << el ;
     ll ans = left - right ;
     for(ll i = 2*n-1 ; i >= n ; --i){
        bool present = false ;
        ll curr = v[i] ;
        if(s1.find(curr)!=s1.end()){
            present =true ;
        }
        ///cout << "present is " << present << " current is " << curr << el ;
        if(present == false){
            auto it = s2.begin() ;
            ll rtt = *it ;
            if(rtt > curr){
                s2.erase(s2.find(rtt));
                s2.insert(curr) ;
                right = right - rtt + curr ;
                ans = max(ans , left - right) ;
                s.erase(s.find(curr));
            }
            /*for(auto &x : s1) cout << x << " " ;
            cout << el ;
            for(auto &x : s2) cout << x << " " ;
            cout << el ;
            for(auto &x : s) cout << x << " " ;
            cout << el ;*/
        }
        else if(present == true) {
            s1.erase(s1.find(curr));
            auto it = s.begin() ;
            ll sl = *it ;
            s.erase(s.find(sl));
            s1.insert(sl);
            left = left - curr + sl ;
            auto itt = s2.begin();
            ll rtt = *itt ;
            if(rtt > curr){
                s2.erase(s2.find(rtt));
                s2.insert(curr);
                right = right - rtt + curr ;
            }
            ans = max(ans , left - right) ;
            /*for(auto &x : s1) cout << x <<" " ;
            cout << el ;
            for(auto &x : s2) cout << x <<" " ;
            cout << el ;
            for(auto &x : s) cout << x << " " ;
            cout << el ;*/
        }
     }
     cout << ans << el ;
}
