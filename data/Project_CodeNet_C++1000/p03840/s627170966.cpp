#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define ppb pop_back
#define ppf pop_front
#define umax(x,y) x=max(x,y)
#define umin(x,y) x=min(x,y)
#define ll long long
#define ii pair<int,int>
#define iii pair<ii,int>
#define iiii pair<ii,ii>
#define sz(x) ((int) x.size())
#define orta ((bas+son)>>1)
#define all(x) x.begin(),x.end()
#define dbgs(x) cerr<<(#x)<<" --> "<<(x)<<" "
#define dbg(x) cerr<<(#x)<<" --> "<<(x)<<endl;getchar()
#define pw(x) (1<<(x))
#define inf 2000000000
#define MOD 1000000007
#define N 200005
#define M 1000005
#define LOG 19
#define KOK 32000
#define EPS 0.000000001
using namespace std;
 
ll s(int I,int O,int J,int L) {

	if(I<0 || J<0 || L<0) return -1ll*inf*inf;

	return 1ll*I/2*2+J/2*2+L/2*2+O;

}

int main() {
 
	int I,O,T,J,L,S,Z;
 
	//freopen("input.txt","r",stdin);
 
	scanf("%d %d %d %d %d %d %d",&I,&O,&T,&J,&L,&S,&Z);

	printf("%lld",max(s(I-1,O,J-1,L-1)+3,s(I,O,J,L)));
	 
}