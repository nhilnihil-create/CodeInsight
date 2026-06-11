#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int int64_t
#define ll long long

void solve()
{
std::map<int, int> mp;
for(int i=0;i<3;i++){
	int x;
	cin>>x;
	mp[x]++;
}

if(mp[5]==2&&mp[7]==1){
	cout<<"YES"<<endl;
}
else{
	cout<<"NO"<<endl;
}


}

int32_t main()
{

	// int test;
	// cin >> test;
	// while (test--)
	{
		solve();
	}
	return 0;
}
