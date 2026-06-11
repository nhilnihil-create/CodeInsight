#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
int a[N];
vector<int>s[9];
void jg(int x){
	if(x>=1&&x<4e2) s[0].pb(x);
	else if(x>=4e2&&x<8e2) s[1].pb(x);
	else if(x>=8e2&&x<1200) s[2].pb(x);
	else if(x>=1200&&x<1600) s[3].pb(x);
	else if(x>=1600&&x<2000) s[4].pb(x);
	else if(x>=2000&&x<2400) s[5].pb(x);
	else if(x>=2400&&x<2800) s[6].pb(x);
	else if(x>=2800&&x<3200) s[7].pb(x);
	else s[8].pb(x);
}
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		jg(a[i]);
	}
	int mn=0,mx=0;
	for(int i=0;i<9;i++){
		if(i!=8){
			if(!s[i].empty()) mn++,mx++;
		}
		else {
		if(!mn) mn++;
		mx+=s[i].size();
		}
	}
	printf("%d %d\n",mn,mx);
	return 0;
}