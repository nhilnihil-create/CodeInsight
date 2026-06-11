#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int N;
	cin>>N;
	vector<int> a(N);
	rep(i,N)
	{
		cin>>a[i];
		a[i]--;
	}
	vector<bool> seen(N,false);
	int k=0;
	int ans=0;
	while(a[k]!=1&&!seen[k])
	{
		seen[k]=true;
		k=a[k];
		ans++;
	}
	if(a[k]!=1)
	{
		cout<<"-1"<<endl;
	}
	else
	{
		cout<<ans+1<<endl;
	}
	return 0;
}
