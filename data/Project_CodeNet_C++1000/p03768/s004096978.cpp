#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
const int inf=2147483647,dx[]={-1,0,1,0},dy[]={0,-1,0,1};
const long long llinf=9223372036854775807ll;
int cl[100005],lst[100005];
vector<int> eds[100005];
int n,m,q;
void dfs(int v,int d,int c)
{
	if(!cl[v])
		cl[v]=c;
	if(lst[v]>=d)
		return ;
	lst[v]=d;
	if(d==0)
		return ;
	for(int u=0;u<eds[v].size();u++)
		dfs(eds[v][u],d-1,c);
}
vector<pair<pair<int,int>,int> > vv;
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		a--,b--;
		eds[a].push_back(b);
		eds[b].push_back(a);  
	}
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int v,d,c;
		cin>>v>>d>>c;
		v--;
		vv.push_back(make_pair(make_pair(v,d),c)); 
	}
	reverse(vv.begin(),vv.end());
	for(int i=0;i<q;i++)
	{
		int v,d,c;
		v=vv[i].first.first;
		d=vv[i].first.second;
		c=vv[i].second;
		dfs(v,d,c);
	}
	for(int i=0;i<n;i++)
		cout<<cl[i]<<'\n';
	return 0;
}