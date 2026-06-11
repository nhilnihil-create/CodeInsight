#include<bits/stdc++.h>
using namespace std;
#define nn 65536*4
#define ll long long
int n,m;
int a[nn];
vector<int> ans,seq;
void solve()
{
	if(seq[0]%2)
	{
		ans.push_back(seq[0]-1);
		ans.push_back(2);
	}
	else
	{
		ans.push_back(seq[0]-1);
		ans.push_back(2);
	}
	
	for(int i=1;i<seq.size()-1;i++)
		ans.push_back(seq[i]);
	
	int cn=seq.size()-1;
	if(seq[cn]%2)
	{
		ans.push_back(seq[cn]-1);
	}
	else
	{
		ans.push_back(seq[cn]-1);	
	}
	
}
void output()
{
	int vnt=0;for(int i=0;i<ans.size();i++) if(ans[i]==0) vnt--;
	cout<<(int)ans.size()+vnt<<"\n";
	for(int i=0;i<ans.size();i++) if(ans[i])printf("%d ",ans[i]);
}
int main()
{
	cin>>n>>m;int od=0;
	for(int i=1;i<=m;i++) scanf("%d",&a[i]),od+=a[i]%2;
	if(m==1) 
	{
		cout<<a[1]<<"\n";
		if(n%2==1)
		{
			while(n>=2) ans.push_back(2),n-=2;
			if(n) ans.push_back(n);
		}
		else
		{
			int t=n/2;if(t%2==0) t++;
			ans.push_back(t);n-=t;
			while(n>=2) ans.push_back(2),n-=2;
			if(n) ans.push_back(n);
		}
		output();
		exit(0);
	}
	if(od>2)
	{
		puts("Impossible");
		exit(0);
	}
	
	if(od==2)
	{
		for(int i=1;i<=m;i++)
			if(a[i]%2)
			{
				seq.push_back(a[i]),a[i]=0;
				break;
			}
		for(int i=1;i<=m;i++) if(a[i]&&a[i]%2==0) seq.push_back(a[i]);
		for(int i=1;i<=m;i++) if(a[i]%2) seq.push_back(a[i]);
			
	}
	if(od==1)
	{
		for(int i=1;i<=m;i++)
			if(a[i]%2)
				seq.push_back(a[i]),a[i]=0;
		for(int i=1;i<=m;i++) if(a[i]&&a[i]%2==0) seq.push_back(a[i]);
	}
	if(od==0)
	{
		for(int i=1;i<=m;i++)
				seq.push_back(a[i]);
	}
	for(int i=0;i<seq.size();i++) printf("%d ",seq[i]);cout<<"\n";
	solve();output();
	return 0;  
}