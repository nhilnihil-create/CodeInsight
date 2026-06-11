#include<bits/stdc++.h>
using namespace std;
void solve(int n,string s,int t1,int t2)
{
	vector<int> v;
	v.push_back(t1);
	v.push_back(t2);
	for(int i=2;i<n;i++)
		v.push_back((v[i-1]+v[i-2]+(s[i-1]=='x'))%2);
	if((v[n-2]+v[n-1]+v[0]+(s[n-1]=='x'))%2==0&&(v[n-1]+v[0]+v[1]+(s[0]=='x'))%2==0)
	{
		for(int i=0;i<n;i++)
			cout<<(v[i]?'W':'S');
		exit(0);
	}
}
int n;
string s;
int main()
{
	cin>>n>>s;
	solve(n,s,0,0);
	solve(n,s,0,1);
	solve(n,s,1,0);
	solve(n,s,1,1);
	cout<<-1<<endl;
	return 0;
}