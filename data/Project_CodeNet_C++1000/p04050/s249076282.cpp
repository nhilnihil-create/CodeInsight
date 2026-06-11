#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
#define w1 first
#define w2 second
#define ls (x<<1)
#define rs (x<<1|1)
#define pb push_back
#define mid ((l+r)>>1)
#define SZ(x) ((x).size())
#define All(x) (x).begin(),(x).end()
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define rep2(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define per(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define Rep(p,x) for(int (p)=head[(x)];(p);(p)=nxt[(p)])
template<class T>void read(T&num){
	num=0;T f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')num=num*10+ch-'0',ch=getchar();
	num*=f;
}
const int maxn=1e5+5;
int cnt=0,n,m;
vector<int>A,B;
int a[maxn];
int main(){
	read(n);read(m);
	rep(i,1,m){
		read(a[i]);
		if(a[i]&1)cnt++;
	}
	if(cnt>2)puts("Impossible");
	else{
		rep(i,1,m)if(a[i]&1){
			A.pb(a[i]);
			break;
		}
		rep(i,1,m)if(!(a[i]&1))A.pb(a[i]);
		if(cnt==2){
			per(i,m,1)if(a[i]&1){
				A.pb(a[i]);
				break;
			}
		}
		rep(i,1,m)printf("%d ",A[i-1]);puts("");
		if(A[0]!=1)B.pb(A[0]-1);
		rep(i,2,m-1)B.pb(A[i-1]);
		if(m>1)B.pb(A[m-1]+1);
		else B.pb(1);
		printf("%d\n",SZ(B));
		rep2(i,0,SZ(B))printf("%d ",B[i]);
	}
	return 0;
}