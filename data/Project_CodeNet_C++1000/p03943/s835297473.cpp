#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	vector <int> v(3);
	for (int i=0; i<3; i++)
		cin>>v[i];
	sort(v.begin(),v.end());
	if (v[0]+v[1]==v[2]) cout<<"Yes";
	else cout<<"No";
	cout<<endl;
	return 0;
}
