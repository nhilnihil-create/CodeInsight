#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 1e5+10;
int n, m;
int x[MAX_N],y[MAX_N];

bool red[MAX_N];
int cnt[MAX_N];

void solve()
{
    for(int i=1;i<=n;++i) cnt[i]=1;
	red[1]=true;
	for(int i=0;i<m;++i){
	    cnt[x[i]]--, cnt[y[i]]++;
		if(red[x[i]]){
			red[y[i]]=true;
		}
		if(!cnt[x[i]]) red[x[i]]=false;
	}
	int ans = 0;
	for(int i=1;i<=n;++i)if(red[i])ans++;
	cout<<ans<<'\n';
}

int main()
{
	cin >> n >> m;
	for(int i=0;i<m;++i){
		cin >> x[i] >> y[i];
	}
	solve();
	return 0;
}