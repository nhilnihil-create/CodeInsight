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

const int N=100005;
int a[N],n,mx;

void GG(){
	puts("Impossible");
	exit(0);
}

int main(){
	read(n);
	rep(i,1,n){
		read(a[i]);
		mx=max(mx,a[i]);
	}
	if(n==2&&a[1]==1&&a[2]==1){
		puts("Possible");
		return 0;
	}
	if(n==2)GG();
	for(int l=1,r=mx+1,t=mx;l<=r;l++,r--,t--){
		int p=0,q=0;
		rep(i,1,n){
			if(!p&&a[i]==t)p=i;
			else if(a[i]==t)q=i;
		}
		if(l!=r){
			if(!p||!q)GG();
			a[p]=a[q]=0;
		}
		else{
			if(!p)GG();
			a[p]=0;
		}
	}
	int mn=mx;
	rep(i,1,n)
		if(a[i])mn=min(mn,a[i]);
	if(mx%2==0&&mn<=mx/2)GG();
	if(mx%2==1&&mn<=mx/2+1)GG();
	puts("Possible");
	return 0;
}
