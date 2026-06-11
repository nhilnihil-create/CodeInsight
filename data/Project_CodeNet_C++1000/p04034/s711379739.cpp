#include<bits/stdc++.h>
#define int long long
#define REP(i,a,n) for(int i=a;i<n;i++)
using namespace std;
int box[100001],red[100001];
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	REP(i,0,n)box[i]=1;
	red[0]=1;
	REP(i,0,m){
		int x,y;
		cin>>x>>y;
		x--;y--;
		box[x]--;box[y]++;
		if(red[x])red[y]=1;
		if(!box[x])red[x]=0;
	}
	int ans=0;
	REP(i,0,n)
	if(red[i])ans++;
	cout<<ans<<endl;
    return 0;
}
