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
struct X
{
	int a,b,c;
};
int n;
int memo[55][401][401];
int ma,mb;
X wa[55];
int solve(int indx,int a,int b){
	if(indx==n){
		if(a && b && (a%ma == 0) && (b%mb ==0 ) && ((a/ma) == (b/mb)))return 0;
		if(a && b && (ma%a == 0) && (mb%b ==0 ) && ((ma/a) == (mb/b)))return 0;
		return 1e9;
	}
	int &ret = memo[indx][a][b];
	if(~ret)return ret;
	ret = min(solve(indx+1,a+wa[indx].a,b+wa[indx].b)+wa[indx].c,
		solve(indx+1,a,b));
	return ret;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();	
	
	scanf("%d %d %d",&n,&ma,&mb);

	for(int i=0;i<n;i++)scanf("%d %d %d",&wa[i].a,&wa[i].b,&wa[i].c);

	memset(memo,-1,sizeof(memo));

	if(solve(0,0,0)>=1e9)printf("-1\n");
	else	printf("%d\n",solve(0,0,0));
}		
