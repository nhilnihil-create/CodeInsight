#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define ppb pop_back
#define ppf pop_front
#define umax(x,y) x=max(x,y)
#define umin(x,y) x=min(x,y)
#define ll long long
#define ii pair<int,int>
#define iii pair<ii,int>
#define iiii pair<ii,ii>
#define sz(x) ((int) x.size())
#define orta ((bas+son)/2)
#define all(x) x.begin(),x.end()
#define dbgs(x) cerr<<(#x)<<" --> "<<(x)<<" "
#define dbg(x) cerr<<(#x)<<" --> "<<(x)<<endl;getchar()
#define pw(x) (1ll<<(x))
#define inf 100000000000000008
#define MOD 998244352
#define N 305	
#define M 1000003
#define C 100000
#define lab(i,j) (((i-1)*n)+j)
#define LOG 19
#define KOK 650
#define EPS 0.0001
using namespace std;

int main() {
 
//	freopen("input.txt","r",stdin);
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int n;
	int a[N][N];

	cin>>n;

	for(int i=1;i<=n;i++) {

		for(int j=1;j<=n;j++) {

			cin>>a[i][j];

		}

	}

	int dp[N][N];

	for(int i=1;i<=n;i++) {

		for(int j=1;j<=n;j++) {

			dp[i][j]=a[i][j];

		}

	}

	ll tot=0;

	for(int i=1;i<=n;i++) {

		for(int j=1;j<=n;j++) {

			bool no=1;

			for(int k=1;k<=n;k++) {

				umin(dp[i][j],dp[i][k]+dp[k][j]);

				if(dp[i][j]==dp[i][k]+dp[k][j]) {

					no&=(k==i || k==j);

				}

			}

			if(dp[i][j]!=a[i][j]) {

				cout<<-1;

				return 0;

			}

			tot+=no*a[i][j];

		}

	}
	cout<<tot/2;

}