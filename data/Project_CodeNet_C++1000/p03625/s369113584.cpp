#include"bits/stdc++.h"
using namespace std;

#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define nl "\n"
#define sp " "
#define int long long
#define PI 3.141592653589793
#define scanstr(s) cin>>ws; getline(cin,s);

int32_t main()
{
	FastIO;
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,greater<int>());
	int ok=0;
	vector<int> p(2);
	int ans=1;
	for(int i=0;i<n;i++)
	{
		if(a[i]==a[i+1])
		{
			ans*=a[i];
			i++;
			ok++;
		}
		if(ok==2) break;
	}
	if(ok==2)
	{
		cout<<ans<<nl;
	}
	else cout<<"0\n";
}
