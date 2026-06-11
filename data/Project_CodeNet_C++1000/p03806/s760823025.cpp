#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define X first
#define Y second
#define pb push_back
#define max_el(x) max_element(x.begin(),x.end())-x.begin()
#define min_el(x) min_element(x.begin(),x.end())-x.begin()
#define mp make_pair
#define endl '\n'
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
// DONT USE MEMSET, USE VECTORS

vector<int> a,b,c;
int n,ma,mb;
int dp[50][500][500];

int f(int i, int ac, int bc){
	if(i == n){
		// cout<<"here"<<endl;
		int g = __gcd(ac,bc);
		if(g == 0){
			return 1e8;

		}
		if(ac/g == ma && bc/g == mb){
			return 0;
		}
		else{
			return 1e8;
		}
	}	
	if(dp[i][ac][bc] != -1){
		return dp[i][ac][bc];
	}

	dp[i][ac][bc] = min(c[i] + f(i+1,ac+a[i],bc+b[i]), f(i+1,ac,bc));
	return dp[i][ac][bc];
}


void solve(){
	memset(dp,-1,sizeof(dp));
	cin>>n>>ma>>mb;
	a.resize(n);
	b.resize(n);
	c.resize(n);
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	int ans = f(0,0,0);
	if(ans < 1e8){
		cout<<ans<<endl;
	}
	else{
		cout<<-1<<endl;
	}
}

int main(){
	// fastread;
	int t = 1;
	// cin>>t;
	for(int i=1;i<=t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
