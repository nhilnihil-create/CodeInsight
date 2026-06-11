#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

#define int long long
#define x first
#define y second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define pb push_back
#define sz(a) (int)(a.size())

typedef long long ll;typedef vector<int> vi;
typedef pair<int,int> ii;typedef vector<ii> vii;
typedef vector<vi> vvi;

using namespace __gnu_pbds;
typedef tree<
ii,
null_type,
less<ii>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

signed main(){
	IOS
	int n,k;cin>>n>>k;
	vi v(n);
	forn(i,n){
		cin>>v[i];v[i]-=k;
		if(i) v[i]+=v[i-1];
	}
	map<int,int> mp;
	int ans = 0;
	ordered_set st;
	int unq=0;
	st.insert({0,++unq});
	forn(i,n){
		ans+=st.order_of_key({v[i],INT_MAX});
		st.insert({v[i],++unq});
	}
	cout<<ans;
}