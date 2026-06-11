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

int n,k;
int ans[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	
	if (k==1 || k==2*n-1){
		cout<<"No"<<endl;
		return 0;
	}
	
	if (n==2){
		cout<<"Yes"<<endl;
		cout<<"1"<<endl;
		cout<<"2"<<endl;
		cout<<"3"<<endl;
		return 0;
	}
	
	vector<int> rem;
	
	if (k==2){
		ans[n-2]=3;
		ans[n-1]=1;
		ans[n]=2;
		ans[n+1]=4;
		
		rep(x,5,2*n) rem.push_back(x);
	}
	else{
		ans[n-2]=k-2;
		ans[n-1]=k+1;
		ans[n]=k;
		ans[n+1]=k-1;
		
		rep(x,1,2*n) if (x<k-2 || k+1<x) rem.push_back(x);
	}
	
	rep(x,1,2*n) if (ans[x]==0){
		ans[x]=rem.back();
		rem.pop_back();
	}
	
	cout<<"Yes"<<endl;
	rep(x,1,2*n) cout<<ans[x]<<endl;
}
