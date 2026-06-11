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
#define endl "\n"
#define pll pair<ll,ll>
#define f first
#define s second
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define int ll
#define sz(x) (ll)x.size()
#define all(x) (x.begin(),x.end())
using namespace std;

 
const ll INF = 1e12;
const ll N =(1e3+5); // TODO : change value as per problem
const ll MOD = 1e9+7;

char a[N][N],b[N][N];
void solve(){
	int n,m;
	cin>>n>>m;	
	for(int i =1;i<=n;i++)
		for(int j = 1;j<=m;j++)
			cin >> a[i][j];
	for(int i = 1;i<=(2*n);i++){
		for(int j = 1;j <=m;j++){
			b[i][j] = a[(i + 1)>>1ll][j];
		}
	}
	for(int i =1;i<=(2*n);i++){
		for(int j =1;j<=m;j++){
			cout<<b[i][j];
		}
		cout<<endl;
	}
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