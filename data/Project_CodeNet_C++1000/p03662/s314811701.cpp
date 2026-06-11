#include<bits/stdc++.h>
using namespace std;
vector<int> contact[300000];
int cnt1[100010];
int cnt2[100010];
bool u[100010]={false};
void dfs(int i,int father,bool is_Fennec)
{
	u[i]=true;
	for(int k=0;k<contact[i].size();k++)
	{
		if(is_Fennec==true)
		{
			cnt1[i]=father+1;
		}
		else
		{
			cnt2[i]=father+1;
		} 
		if(!u[contact[i][k]])
		{
			dfs(contact[i][k],father+1,is_Fennec);
		}
	}
	return;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		contact[a].push_back(b);
		contact[b].push_back(a);
	}
	/*cout<<endl;
	for(int j=1;j<=n;j++)
	{
		cout<<j<<':';
		for(int k=0;k<contact[j].size();k++)
		{
			cout<<contact[j][k]<<",";
		}
		cout<<endl;
	}
	cout<<endl;*/
	dfs(1,-1,true);
	memset(u,false,sizeof(u));
	dfs(n,-1,false);
	int f=0,s=0; 
	for(int j=1;j<=n;j++)
	{
		if(cnt1[j]<=cnt2[j])
		{
			f++;
		}
		else 
		{
			s++;
		}
	}
	if(f>s)
	{
		cout<<"Fennec";
	}
	else
	{
		cout<<"Snuke";
	}
	return 0;
}