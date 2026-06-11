#include<bits/stdc++.h>
using namespace std;
int n,a[100010];
string s;
vector<int> check(int x,int y)
{
	vector<int> v;
	v.push_back(x);
	v.push_back(y);
	for(int i=2;i<n;i++)
	{
		if(!a[i-1])
		{
			if(v[i-1]==0)
				v.push_back(v[i-2]);
			else
				v.push_back(1-v[i-2]);
		}
		else
		{
			if(v[i-1]==0)
				v.push_back(1-v[i-2]);
			else
				v.push_back(v[i-2]);
		}
	}
	if((a[n-1])==(v[n-2]^v[n-1]^v[0])&&(a[0])==(v[n-1]^v[0])^v[1])
		return v;
	v.clear();
	return v;
}
void printans(vector<int> v)
{
	for(int i=0;i<v.size();i++)
		cout<<(v[i]==0?'S':'W');
	exit(0);
}
int main()
{
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='o')
			a[i]=0;
		else
			a[i]=1;
	}
	vector<int> v;
	v=check(0,0);
	if(v.size()!=0)
		printans(v);
	v=check(0,1);
	if(v.size()!=0)
		printans(v);
	v=check(1,0);
	if(v.size()!=0)
		printans(v);
	v=check(1,1);
	if(v.size()!=0)
		printans(v);
	cout<<-1<<endl;
	return 0;
}