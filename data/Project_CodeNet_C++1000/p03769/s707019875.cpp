#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
#define inf 0x3f3f3f3f
#define clr(a,x) memset(a,x,sizeof(a))
using namespace std;
 
const int N=100005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}
 
int t,tot,a[505],b[505],s[505];
int la=201,ra=200,lb=201,rb=200;
 
void solve(ll n){
	if(n==1){
		++tot;
		a[--la]=tot;b[--lb]=tot;
		return;
	}
	if(n&1){
		solve(n/2);
		++tot;
		a[--la]=tot;b[--lb]=tot;
	}
	else{
		solve(n-1);
		++tot;
		a[--la]=tot;b[++rb]=tot;
	}
}
 
int main(){
	ll n;cin>>n;
	solve(n);
	printf("%d\n",ra-la+rb-lb+2);
	for(int i=la;i<=ra;i++)
		printf("%d ",a[i]);
	for(int i=lb;i<=rb;i++)
		printf("%d ",b[i]);
	return 0;
}