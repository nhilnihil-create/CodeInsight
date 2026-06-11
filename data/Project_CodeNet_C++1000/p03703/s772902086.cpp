#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define nmax 200005

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

typedef tree<
ll,
null_type,
less_equal<ll>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

ll a[nmax]={};

int main(){
	int n,k; cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		a[i]+=a[i-1];
	}
	ordered_set s;
	s.insert(0);
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=s.order_of_key(a[i]-1ll*k*i+1);
		s.insert(a[i]-1ll*k*i);
	}
	cout << ans << endl;
	return 0;
}

