#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define debug(x) cerr<<#x" = "<<x<<endl
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7;//*
inline int rd() {
	int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
	while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
inline char rc(){char c;while((c=getchar())!='Y'&&c!='N');return c;}
bool que(ll x){
	printf("? %lld\n",x);
	fflush(stdout);
	return rc()=='Y';
}
int main(){
	ll l,r;
	if(que(10000000000)){
		for(r=2;;r*=10)if(que(r))
			return cout<<"! "<< r/2<<endl,0;
	}
	for(r=10;;r*=10)if(!que(r))break;
	l=r/10,r--;
	while(l<r){
		ll mid=l+r>>1;
		if(que(mid*10))r=mid;
		else l=mid+1;
	}
	cout<<"! "<<l<<endl;
}