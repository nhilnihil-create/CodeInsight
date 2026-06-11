#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define N 200000
#define MOD 1000000007
using namespace std;
using namespace __gnu_pbds;
typedef long long LL;
template<typename T>
using indexed_set = tree<T,null_type,less<T>,rb_tree_tag, tree_order_statistics_node_update>;

LL a[N+1];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	LL n, k; cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	indexed_set<pair<LL,int> > tracker;
	tracker.insert({0,0});

	LL sum = 0;
	LL ans = 0;
	for(LL i = 1; i <= n; i++)
	{
		sum += a[i];
		//Count number of PST[j] such that (PST[i]-PST[j])/(i-j) >= k, or PST[i]-PST[j] >= ki - kj
		//PST[i]-ki >= PST[j]-kj or
		//(PST[i]-ki,i) > (PST[j]-kj,j)
		ans += (LL)tracker.order_of_key({sum-k*i,i});
		tracker.insert({sum-k*i,i});
	}
	cout<<ans<<endl;

	return 0;
}