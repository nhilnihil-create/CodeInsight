
// Problem : B - Colorful Creatures
// Contest : AtCoder - AtCoder Grand Contest 011
// URL : https://atcoder.jp/contests/agc011/tasks/agc011_b
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;
 
//krishrawat 
 
 
//----------------------------MACROS-------------------------------------------------
#define pb insert//                                                                 |
#define eb emplace_back//                                                           |
#define ff first//                                                                  |
#define ss second//                                                                 |
typedef long long int ll;//                                                         |
typedef long double ld;//                                                           |
#define all(a) a.begin(), a.end()//                                                 |
#define show(x) cerr << #x << " is " << x << "\n"//                                 |
#define show2(x, y) cerr << #x << " " << #y << " " << x << " " << y << "\n"//       |
typedef vector<ll> vl;//                                                            |
typedef vector<vl> vvl;//                                                           |
typedef pair<ll, ll> pp;//                                                          |
typedef vector<pp> vp;//                                                            |
typedef map<pp, ll> ipi;//                                                          |
typedef map<pp, char> ipc;//                                                        |
typedef map<ll, ll> ii;//                                                           |
typedef set<ll> sl;//                                                               |
typedef multiset<ll> msl;//                                                         |
typedef map<char, ll> ci;//                                                         |
typedef set<pair<ll, ll>> sp;//                                                     |
const ll mod = 1e9 + 7;//                                                           |
const ll N = 1e6 + 1;//                                                             |
//----------------------------------------------------------------------------------
 
 
void solve(){
    ll n;cin>>n;
    vp v;
    for(int i=0;i<n;i++){
    	ll k;cin>>k;
    	v.eb(k,i);
    }
    sort(all(v));
    vl vis(n,0);
    ll sums=0;
    vis[n-1]=1;
    for(int i=0;i<n-1;i++){
    	sums+=v[i].ff;
    	if(v[i+1].ff<=2*sums){
    		vis[i]=1;
    	}
    }
    
    ll ans=0;
    for(int i=n-1;i>=0;i--){
    	if(vis[i]){
    		ans++;
    	}
    	else break;
    }
    cout<<ans<<"\n";
}
 
int main()
{	
	/*#ifndef ONLINE_JUDGE 
   		freopen("input.txt", "r", stdin);  
   		freopen("output.txt", "w", stdout); 
   	#endif*/
 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
     
 
    ll t;
    t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    
	return 0;
}