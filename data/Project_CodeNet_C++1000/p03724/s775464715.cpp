#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int N,M,a,b; cin>>N>>M;
	map<int,int> ct;
	for (int i=0; i<M; i++) {
		cin>>a>>b;
		ct[a]++; ct[b]++;
	}

	for (auto it : ct)
		if(it.second%2) {
			cout<<"NO\n";
			return 0;
		}
	cout<<"YES\n";
	return 0;
}