#include <iostream>
//#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <queue>
//#include <deque>
//#include <bitset>
#include <math.h>
using namespace std ;
using ll = long long ;
//using ld = long double ;
using vll = vector<ll> ;
using vvll = vector<vll> ;
using vc = vector<char> ;
using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
using pll = pair<ll,ll> ;
#define all(v) v.begin(),v.end()
ll mod = 1000000007 ;
//long double pie = acos(-1) ;
ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}
void chmax(ll &a,ll b){	if(a<b) a = b ;}
void chmin(ll &a,ll b){ if(a>b) a = b ;}

int main(){
    ll n ; cin >> n ;
    vll a(n),b(n),h(n,-1) ;
    for(auto &i:a) cin >> i ;
    for(auto &i:b) cin >> i ;
    for(int i=0;i<n;i++) if(i==0||a[i-1]<a[i]) h[i] = a[i] ;
    for(int i=n-1;i>=0;i--){
        if(i==n-1||b[i]>b[i+1]){
            if(h[i]!=-1&&h[i]!=b[i]){
                cout << 0 << endl ;
                return 0 ;
            }
            h[i] = b[i] ;
        }
    }
    ll mx = 0 ;
    for(int i=0;i<n;i++){
        chmax(mx,h[i]) ;
        if(mx!=a[i]){
            cout << 0 << endl ;
            return 0 ;
        }
    }
    mx = 0 ;
    for(int i=n-1;i>=0;i--){
        chmax(mx,h[i]) ;
        if(mx!=b[i]){
            cout << 0 << endl ;
            return 0 ;
        }
    }
    ll ans = 1 ;
    for(int i=0;i<n;i++){
        if(h[i]!=-1) continue ;
        ans = ans*min(a[i],b[i])%mod ;
    }
    cout << ans << endl ;
}