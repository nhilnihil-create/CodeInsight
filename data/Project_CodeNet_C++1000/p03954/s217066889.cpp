#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl;

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
int arr[200005];

bool can(int i){
	int best=1000000;
	bool val;
	
	rep(x,2,2*n){
		int temp=min(abs(x-1-n),abs(x-n));
		
		if (arr[x-1]<=i && arr[x]<=i){
			if (temp<best){
				best=temp;
				val=true;
			}
		}
		else if(arr[x-1]>i && arr[x]>i){
			if (temp<best){
				best=temp;
				val=false;
			}
		}
	}
	
	if (best!=1000000) return val;
	else return (arr[n]<=i)!=(n%2==0);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	rep(x,1,2*n) cin>>arr[x];
	
	//rep(x,1,2*n) cout<<x<<" "<<can(x)<<endl;
	//return 0;
	
	int lo=1,hi=2*n,mi;
	
	while (hi-lo>1){
		mi=hi+lo>>1;
		
		if (can(mi)) hi=mi;
		else lo=mi;
	}
	
	cout<<hi<<endl;
}
