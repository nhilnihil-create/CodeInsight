//nays//nays//nays//nays//nays//nays//nays//nays//nays//nays//nays
//nays//nays//nays//nays//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays
//nays

#include <bits/stdc++.h>
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
#define orta ((bas+son)/2)
#define all(x) x.begin(),x.end()
#define dbgs(x) cerr<<(#x)<<" --> "<<(x)<<" "
#define dbg(x) cerr<<(#x)<<" --> "<<(x)<<endl;getchar()
#define pw(x) (1ll<<(x))
#define inf 1000000000
#define MOD 1000000007
#define N 2000005
#define M 1000003
#define LOG 16
#define KOK 650
#define EPS 0.00001
using namespace std;
 
int f[N],p[N],n;
 
int main() {
 
//	freopen("input.txt","r",stdin);
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
 
	cin>>n;
 
	f[1]=n;
 
	for(int i=0;i<=M;i++) p[i]=(p[i-1]+1)%MOD;
 
	p[1+M]=(p[M]+n)%MOD;
 
	for(int i=2;i<=n;i++) {
 
		f[i]=(p[i-3+M]-p[i-n-2+M]+f[i-1]+(ll)(n-1)*(n-1))%MOD;
		
		p[i+M]=(p[i-1+M]+f[i])%MOD;
 
	}
 
	cout<<f[n];
 
}