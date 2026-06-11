#include<bits/stdc++.h>
using namespace std;
#define IL inline
#define rep(i,j,k) for(int i=j;i<=k;++i)
#define repd(i,j,k) for(int i=j;i>=k;--i)
#define pb push_back
#define db double
#define mp make_pair
#define mp3(a,b,c) mp(mp(a,b),c)
#define pii pair<int,int>
#define piii pair<pii,int>
#define fr first
#define se second
#define ll long long
#define ull unsigned long long
#define pbc(x) __builtin_popcount(x)
#define clr(x) memset(x,0,sizeof x)
#define SIZE(x) (int)(x.size())
const int mod=1e9+7;
IL int pls(int x,int y){x+=y;return x>=mod?x-mod:x;}
IL int dec(int x,int y){x-=y;return x<0?x+mod:x;}
IL int mul(int x,int y){return 1ll*x*y%mod;}
IL int mul(int x,int y,int z){return mul(mul(x,y),z);}
IL int mul(int x,int y,int z,int p){return mul(mul(x,y),mul(z,p));}
IL void add(int &x,int y){x+=y;x=(x>=mod)?x-mod:x;}
IL int fpw(int x,int y,int r=1){for(;y;y>>=1,x=mul(x,x))if(y&1)r=mul(r,x);return r;}
IL int inv(int x){return fpw(x,mod-2);}
IL int gi(){int x;int _w=scanf("%d",&x);return x;}
IL void gi(int &x){int _w=scanf("%d",&x);}
IL void write(int x){printf("%d\n",x);}
void chkmax(int &x,int y){x=(x>y)?x:y;}
void chkmin(int &x,int y){x=(x<y)?x:y;}
const int INF=0x3f3f3f3f;
template<typename T>IL void debug(T x){cerr<<x;return;}
/* --------------------------------------------------------------------------------------------------------- */
const int maxn=1e5+10;
int n;
int a[maxn];
namespace sub1{
	const int sub1_maxn=3005;
	int SG[sub1_maxn][sub1_maxn];
	IL bool check(){
		return 0;
		int mx=0;
		rep(i,1,n)chkmax(mx,a[i]);
		return n<=3000&&mx<=3000;
	}
	int workSG(int x,int y){
		if(SG[x][y]!=-1)return SG[x][y];
		SG[x][y]=0;
		int &ans=SG[x][y];
		set<int>q;
		if(y+1<=a[x])q.insert(workSG(x,y+1));
		if(x+1<=n&&y<=a[x+1])q.insert(workSG(x+1,y));
		while(q.count(ans))ans++;
		return ans;
	}
	IL void work(){
		memset(SG,-1,sizeof SG);
		workSG(1,1);
		rep(i,1,n){rep(j,1,a[i])cerr<<SG[i][j]<<' ';cerr<<endl;}
		puts(SG[1][1]?"First":"Second");
	}
}
namespace sub2{
	int last[maxn];
	IL bool check(int cor){
		if(cor==n)return false;
		int cur=last[cor]?((a[cor]-a[cor+1])&1):((a[cor]-a[cor+1])%2);
		return cur==last[cor+1];
	}
	IL void work(){
		int p;
		rep(i,1,n)if(i<=a[i])p=i;
		last[n]=0;
		repd(i,n-1,1)last[i]=(a[i]==a[i+1])?(!last[i+1]):0;
		if(check(p)){
			if(p>a[p+1]){
				int cur=last[p]?((a[p]-p)&1):((a[p]-p)%2);
				puts(cur?"First":"Second");
			}else{
				int cur=1;
				puts(cur?"First":"Second");
			}
		}else{
			int cur=(a[p]-p)%2;
			cur=last[p]?(!cur):cur;
			puts(cur?"First":"Second");
		}
	}
}
int main(){
	#ifdef LOCAL
		freopen("/home/noilinux/Desktop/input.txt","r",stdin);
	#endif
	n=gi();
	rep(i,1,n)a[i]=gi();
	sort(a+1,a+1+n,greater<int>());
	if(sub1::check())sub1::work();
	else sub2::work();
	return 0;
}
/*
2 0 1 0 1 0 1 0 2 1 0 1 0 1 0 1 0 
1 2 0 1 0 1 0 1 0 2 1 0 
0 1 2 0 1 0 1 0 1 0 
1 0 1 2 0 1 0 1 
0 1 0 1 2 0 1 0 
1 0 1 0 1 2 0 1 
0 1 0 1 0 1 2 0 
1 0 1 0 1 0 1 
2 1 0 1 0 1 0 
0 2 1 0 1 0 
1 0 2 1 0 
0 1 0 
First 
*/