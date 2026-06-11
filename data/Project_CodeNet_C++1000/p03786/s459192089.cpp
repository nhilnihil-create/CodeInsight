#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

bool ok(int idx, vector<ll> &A, int N) {
	ll cur=0;
	for (int i=0; i<=idx; i++)
		cur+=A[i];
	for (int i=idx+1; i<N; i++) {
		if(cur*2<A[i])
			return false;
		cur+=A[i];
	}
	return true;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int N; cin>>N;
	vector<ll> A(N);
	for (int i=0; i<N; i++)
		cin>>A[i];
	sort(A.begin(),A.end());
	int low=0, high=N-1;
	while(low<high) {
		int mid=(low+high)/2;
		if(ok(mid,A,N)) high=mid;
		else low=mid+1;
	}
	cout<<N-low<<"\n";
	return 0;
}