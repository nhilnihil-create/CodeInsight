#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
using ld = long double;
int C[52][52];
int ncr(int n,int r)
{
	return C[n][r];
}
int32_t main()
{
	
	for(int i=0;i<=50;i++)C[i][0]=1;
	for(int i=1;i<=50;i++)
	for(int j=1;j<=50;j++)
	{
		C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	
	
	
	int n;
	cin>>n;
	int a[n];
	int A,B;cin>>A>>B;
	map<int,int> f;
	for(auto &i:a)
	{cin>>i;f[i]++;}
	
	sort(a,a+n);
	reverse(a,a+n);
	int pre[n+1];
	pre[0]=0;
	for(int i=1;i<=n;i++)pre[i]=a[i-1]+pre[i-1];
	vector<ld> val;
	vector<pair<int,int>> sid;
	for(int i=A;i<=B;i++)
	{
		ld sum=((ld)pre[i])/(ld)i;
		val.push_back(sum);
		sid.push_back({pre[i],i});
	}
	
	ld mx=*max_element(val.begin(),val.end());
	cout<<fixed<<setprecision(6)<<mx<<"\n";
	int ways=0;
	for(auto i:sid)
	{
		int reqd=i.second;
		int sum=i.first;
		ld test=(ld)sum/(ld)reqd;
		if(test!=mx)continue;
		map<int,int> re;
		for(int i=0;i<reqd;i++)
		{
			re[a[i]]++;
		}
		int pro=1;
		for(auto j:re)
		{
			pro*=ncr(f[j.first], j.second);
		}
		ways+=pro;
		
	}
	cout<<ways;
	
	
}