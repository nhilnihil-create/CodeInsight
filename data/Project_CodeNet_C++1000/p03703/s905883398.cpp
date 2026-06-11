#include<iostream>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<pair<long long,int>,null_type,less<pair<long long,int>>,rb_tree_tag,tree_order_statistics_node_update>rbt;
rbt s;
int n,a,k,tot;long long tag,ans;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a,a-=k;
		tag+=a;
		s.insert(make_pair(a-tag,++tot));
		ans+=i-s.order_of_key(make_pair(-tag,0));
	}
	cout<<ans;
	return 0;
}