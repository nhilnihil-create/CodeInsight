#include<bits/stdc++.h>

#define REP(i,a,b) for(int i=a,i##_end_=b;i<=i##_end_;++i)
#define DREP(i,a,b) for(int i=a,i##_end_=b;i>=i##_end_;--i)
#define MREP(i,x) for(int i=beg[x],v;v=to[i],i;i=las[i])
#define debug(x) cout<<#x<<"="<<x<<endl
#define fi first
#define se second
#define mk make_pair
#define pb push_back
typedef long long ll;

using namespace std;

void File(){
	freopen("pyramid.in","r",stdin);
	freopen("pyramid.out","w",stdout);
}

template<typename T>void read(T &_){
	T __=0,mul=1; char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')mul=-1;
		ch=getchar();
	}
	while(isdigit(ch))__=(__<<1)+(__<<3)+(ch^'0'),ch=getchar();
	_=__*mul;
}

const int maxn=4e6+10;
int n,a[maxn],c[maxn];
int b[2][maxn];

/*void tran(){
	read(n);
	int now=0,las=1;
	REP(i,1,n*2-1)read(b[las][i]);
	REP(i,1,n){
		REP(j,1,n*2-1){
			if(j<i || j>n*2-i)cout<<"  ";
			else cout<<b[las][j]<<" ";
		}
		cout<<endl;
		if(i==n)break;
		REP(j,1+i,n*2-1-i){
			int c[2]={0};
			++c[b[las][j]];
			++c[b[las][j-1]];
			++c[b[las][j+1]];
			b[now][j]=c[0]>c[1] ? 0 : 1;
		}
		swap(las,now);
	}
}*/

bool judge(int x){
	REP(i,1,n*2-1)c[i]=(a[i]>x);
	if(c[n]==c[n-1] || c[n]==c[n+1])return !c[n];
	int L=n,R=n,len;
	while(L>2 && c[L-1]!=c[L-2] && c[L-1]!=c[L])--L;
	while(R<n*2-2 && c[R+1]!=c[R+2] && c[R+1]!=c[R])++R;
	len=min(n-L+1,R-n+1);
	if(len%2)return c[n];
	return !c[n];
}

int main(){
	//File();
	read(n);
	REP(i,1,n*2-1)read(a[i]);
	if(n==1)return printf("%d\n",a[1]),0;
	int l=1,r=n*2-1;
	while(l<r){
		int mid=(l+r)>>1;
		if(judge(mid))r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}