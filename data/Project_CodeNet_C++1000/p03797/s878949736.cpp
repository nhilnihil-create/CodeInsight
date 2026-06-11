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
int main(){	
	ll n,m;
	cin>>n>>m;
	if(m-2*n<4) cout<<min(m/2,n);
	else cout<<n+(m-2*n)/4;
	return 0;
}