#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

ll ans = 100000000;
int n;
int hate[10];

void dfs(int now)
{
	if(n<=now)
	{
		ans = min<ll>(now,ans);
		return;
	}
	for(int i = 0;i<10;i++)
	{
		if(now*10+i==0)continue;
		if(hate[i]==0)dfs(now*10+i);
	}
}

int main()
{
	int k;
	cin >> n >> k;
	for(int i = 0;i<k;i++)
	{
		int x;
		cin >> x;
		hate[x] = 1;
	}
	dfs(0);
	cout<<ans<<endl;


}
