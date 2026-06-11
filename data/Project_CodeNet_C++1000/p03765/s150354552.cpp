#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define maxn 100005
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pp;
const long long inf = 2e18;
int n,m,q; string s,t; int c1[maxn][2],c2[maxn][2];
main(){
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen(".inp","r",stdin); freopen(".out","w",stdout);
	//freopen("inp.txt","r",stdin);
	cin>>s>>t; n=s.size(); m=t.size(); int i,j,k;
	s='?'+s; t='?'+t;
	cin>>q;
	for (i=1;i<=n;i++){
		c1[i][0]=c1[i-1][0]; c1[i][1]=c1[i-1][1];
		if (s[i]=='A') c1[i][0]++;
		else c1[i][1]++;
	}
	for (i=1;i<=m;i++){
		c2[i][0]=c2[i-1][0]; c2[i][1]=c2[i-1][1];
		if (t[i]=='A') c2[i][0]++; else c2[i][1]++;
	}
	int a,b,c,d;
	while (q--){
		cin>>a>>b>>c>>d;
		int h1=(c1[b][0]-c1[a-1][0])-(c1[b][1]-c1[a-1][1]);
		int h2=(c2[d][0]-c2[c-1][0])-(c2[d][1]-c2[c-1][1]);
		h1%=3; if (h1<0) h1+=3; 
		h2%=3; if (h2<0) h2+=3;
		if (h1==h2) cout<<"YES\n";
		else cout<<"NO\n";
	}
}