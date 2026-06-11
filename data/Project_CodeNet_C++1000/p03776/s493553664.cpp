#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long



using namespace std;

void file(){
	#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
	#endif
}
int tc;
const int N=5e5+5,M=2e6+5,MOD=1e9+7,OO=1e9;
ll C[55][55];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();	
	
	int n,aa,b;

	for(int i=0;i<=50;i++){
		for(int j=0;j<=i;j++){
			if(j==0 || j==i)C[i][j]=1;
			else	C[i][j]=C[i-1][j-1]+C[i-1][j];
		}
	}
	scanf("%d %d %d",&n,&aa,&b);

	std::vector<ll> a(n);
	map<double,ll>ways;
	double ans = 0;
	map<ll,int>occ;
	for(int i=0;i<n;i++)scanf("%lld",&a[i]),occ[a[i]]++;
	double curr = 0 ;
	map<ll,int>wa;
	sort(all(a));
	for(int i=n-1;i>=n-aa;i--){
		if((n-i)>b)break;
		curr+=a[i];
		wa[a[i]]++;
		if((n-i)>=aa){
			if(ans == 0 || (ans-curr/(n-i)) <= 0){
				ans = curr/(n-i);
				ll x = 1;
				for(auto p : wa){
					x*=C[occ[p.first]][p.second];
				}
				ways[ans]+=x;
			}
		}
	}
	if(a[n-1]==a[n-aa]){
		for(int i=aa;i<min(b,occ[a[n-aa]]);i++)ways[ans]+=C[occ[a[n-aa]]][i+1];
	}
	printf("%.9lf\n%lld",ans,ways[ans] );
}		
