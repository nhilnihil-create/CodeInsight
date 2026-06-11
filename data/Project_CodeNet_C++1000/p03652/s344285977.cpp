#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
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

const int N=305;
int mark[N],c[N],n,m,ans;
vi p[N];

int main(){
	read(n),read(m),ans=n;
	rep(i,1,n){
		p[i].resize(m);
		per(j,m-1,0) read(p[i][j]);
	}
	rep(i,1,m){
		fill(c+1,c+m+1,0);
		rep(j,1,n){
			while(mark[p[j].back()]) p[j].pop_back();
			c[p[j].back()]++;
		}
		int mx=0;
		rep(j,1,m) if(c[j]>c[mx]) mx=j;
		ans=min(ans,c[mx]);
		mark[mx]=1;
	}
	cout<<ans<<endl;
	return 0;
}