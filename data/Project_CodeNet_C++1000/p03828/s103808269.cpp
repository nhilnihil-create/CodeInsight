#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
#define re return
#define all(a) a.begin(),a.end()
#define int long long
using namespace std;
int prime[1010];
vector<pair<int,int> >par[1010];
int pr2[1010];
int ans;
signed main()
{
	int n;
	cin>>n;
	ans=1;
	for (int i=2;i<1008;i++)
		if (!prime[i])
			for (int j=i;j<=1008;j+=i){
				prime[j]=1;
				int d=0,h=j;
				while (h%i==0){
					h/=i;
					d++;
				}
				par[j].pb(mp(i,d));
				//cout<<j<<' '<<i<<' '<<d<<endl;
			}
	for (int i=2;i<=n;i++){
		for (int j=0;j<sz(par[i]);j++){
			pr2[par[i][j].first]+=par[i][j].second;
			//cout<<par[i][j].first<<' '<<par[i][j].second<<' '<<i<<endl;
		}
	} 
	for (int i=0;i<=n;i++){
		ans=(ans*(pr2[i]+1))%1000000007;
	}
	cout<<ans;
	re 0;
}
