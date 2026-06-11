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

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();	

	int n,m;

	scanf("%d %d",&n,&m);
	std::vector<tuple<int,int,int>> edges(m,tuple<int,int,int>(0,0,0));
	for(int i=0,a,b,c;i<m;i++)scanf("%d %d %d",&a,&b,&c),edges[i]=make_tuple(a,b,c);

	std::vector<ll> dist(n+1,-1e18);
	
	dist[1]=0;
	for(int i=1;i<n;i++){
		for(auto e : edges){
			int a,b,c;
			tie(a,b,c) = e;
			if(dist[b]<dist[a]+c){
				dist[b]=dist[a]+c;
			}
		}

	}
	
	for(auto e : edges){
		int a,b,c;
		tie(a,b,c) = e;

		if(b==n && dist[n]<dist[a]+c){
			return !printf("inf\n");
		}
		if(dist[b]<dist[a]+c)dist[b]=dist[a]+c;	
	}

	printf("%lld\n",dist[n] );
}		
