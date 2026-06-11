		#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <ratio>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <climits>
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define in insert
#define vll vector<ll>
#define pll pair<ll,ll>
#define f first
#define s second
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define int ll
#define sz(x) (ll)x.size()
#define all(x) (x.begin(),x.end())
using namespace std;

 
const ll INF = 1e12;
const ll N =(1e5+5); // TODO : change value as per problem
const ll MOD = 1e9+7;
int x[N],y[N];
bool red[N];
int balls[N];
void solve(){
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		cin >> x[i] >> y[i];
	}
	red[1] = true;
	for(int i = 1;i<=n;i++){
		balls[i] = 1;
	}
	for(int i =1;i<=m;i++){
		int from = x[i],to  =y[i];
		if(red[from]){
			if(balls[from] == 1) {
				red[from] = false;
				balls[from] = 0;
			}
			else balls[from]--;
			red[to] = true;
			balls[to]++;
		}
		else{
			balls[from]--;
			balls[to]++;
		}
 	}int ans = 0;
 	for(int i = 1;i<=n;i++){
 		if(red[i]){
 			ans++;
 		}
 	}
 	cout << ans << endl;
}
signed main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
     // freopen(".in","r",stdin);freopen(".out","w",stdout);
    
     ll tt=1;   
     // cin >> tt;
    while(tt--){    
        solve();
    }    
}