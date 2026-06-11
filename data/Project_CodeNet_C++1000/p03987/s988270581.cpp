#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &i:a)cin >> i;
	set<int> H,W;
	H.insert(n);
	W.insert(n);
	vector<int> b(n);
	for(int i = 0;i<n;i++)
		b[a[i]-1]=i;
	ll ans = 0;
	for(int i = 0;i<n;i++)
	{
		ll now = 0;
		now = *H.lower_bound(b[i])-b[i];
		now *= *W.lower_bound(n-b[i]-1)-(n-b[i]-1);
		H.insert(b[i]);
		W.insert(n-b[i]-1);
		ans += now*(1+i);

	}
	cout<<ans<<endl;

}
