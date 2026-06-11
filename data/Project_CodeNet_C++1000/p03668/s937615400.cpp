#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
#define pi pair<int,int>
#define pii pair<pi,int>
#define aa first
#define bb second
#define xx aa.aa
#define yy aa.bb
#define zz bb
#define mp make_pair
#define mpp(a,b,c) mp(mp(a,b),c)
using namespace std;
int n;
vi a[100010];
inline int dp(int i,int j)
{
	int p=0;
	for(auto k:a[i])
	  if(k!=j)
	    p^=dp(k,i)+1;
	return p;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	  {
	   scanf("%d%d",&j,&k);
	   a[j].pb(k);
	   a[k].pb(j);
	  }
	if(dp(1,0))
	  printf("Alice");
	else
	  printf("Bob");
	return 0;
}
