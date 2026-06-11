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

int n,k;
int arr[100005];
bool red[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	for (int x=1;x<=n;x++) arr[x]=1;
	red[1]=true;
	
	int a,b;
	while (k--){
		cin>>a>>b;
		arr[a]--;
		arr[b]++;
		if (red[a]) red[b]=true;
		if (arr[a]==0) red[a]=false;
	}
	
	int ans=0;
	for (int x=1;x<=n;x++) if (red[x]) ans++;
	cout<<ans<<endl;
}
