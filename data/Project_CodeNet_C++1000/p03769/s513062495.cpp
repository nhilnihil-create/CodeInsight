#include<bits/stdc++.h>
using namespace std; 
#define int long long 
#define mp make_pair
#define pb push_back
#define pii pair<ll,int>
#define F first
#define S second
#define ld long double
int const M=1000+10,M2=1e3+10,mod=1e9+7,inf=1e9+10;
int cnt=1;
vector<int>ans1,ans2;
void fans(int x)
{
	if(x==0)return;
	if(x%2==0)fans(x-1);
	else
		fans(x/2);
	if(x%2==0)
	{
		reverse(ans1.begin(),ans1.end());
		ans1.pb(cnt);
		reverse(ans1.begin(),ans1.end());
		ans2.pb(cnt);
		cnt++;
	}
	else
	{
		ans1.pb(cnt);
		ans2.pb(cnt);
		cnt++;
	}
}
int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	//n++;
	fans(n);
	cout<<ans1.size()*2<<endl;
	for(int i=0;i<ans1.size();i++)cout<<ans1[i]<<" ";
	for(int i=0;i<ans2.size();i++)cout<<ans2[i]<<" ";
}