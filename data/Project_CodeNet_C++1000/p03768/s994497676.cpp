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
int c[100005][11],clr[100005],n,m,q;
vector<int> e[100005];
int main(){ 
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		a--,b--;
		e[a].push_back(b);
		e[b].push_back(a);  
	}
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int v,d;
		cin>>v>>d>>clr[i+1];
		v--;
		c[v][d]=i+1;
	}
	for(int i=9;i>=0;i--)
		for(int v=0;v<n;v++)
			for(int u=0;u<e[v].size();u++)
				if(c[e[v][u]][i]<c[v][i+1])
					c[e[v][u]][i]=c[v][i+1];
	for(int v=0;v<n;v++)
	{
		int ans=0;
		for(int d=0;d<11;d++)
			if(ans<c[v][d])
				ans=c[v][d];
		cout<<clr[ans]<<'\n';
	}
	return 0;
}