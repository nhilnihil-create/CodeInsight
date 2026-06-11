#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define qwq(x) cerr<<" #"<<#x<<" = "<<x<<endl;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
 
template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=1000005;
ll I,O,T,J,L,ans,now;

void doit(ll x){
	if(I<x||J<x||L<x||x<0)return;
	ans=max(ans,x*3+(I-x)/2*2+(J-x)/2*2+(L-x)/2*2);
}

int main(){
	read(I),read(O);
	read(T),read(J),read(L);
	REP(t,10)doit(t),doit(min(J,L)-t);
	ans+=O;
	cout<<ans<<endl;
	return 0;
}
