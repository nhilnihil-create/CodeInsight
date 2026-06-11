# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
# define MOD 1000000007
using namespace std;
ll dp [2500]{0};
ll dp2 [2500]{0};
int main(){
	fastio;
	int n,k,tmp;
	cin>>n>>k;
	vector <int> l0,g0;
	ll num0=0;
	for (int i=0;i<n;i++){
		cin>>tmp;
		tmp-=k;
		if (tmp==0) num0++;
		else if (tmp<0) l0.push_back(-tmp);
		else g0.push_back(tmp);
	}
	sort(all(l0));sort(all(g0));
	dp[0]=1;dp2[0]=1;
	for (int i=0;i<l0.size();i++){
		for(int x=2499;x>0;x--){
			int t=x-l0[i];
			if (t<0)continue;
			dp[x]+=dp[t];
		}
	}
	for (int i=0;i<g0.size();i++){
		for(int x=2499;x>0;x--){
			int t=x-g0[i];
			if(t<0) continue;
			dp2[x]+=dp2[t];
		}
	}
	ll re=0;
	for(int i=0;i<2500;i++){
		 re+=dp[i]*dp2[i];
	}
	re*=(1LL<<num0);

	cout<<re-1<<'\n';
	return 0;
}