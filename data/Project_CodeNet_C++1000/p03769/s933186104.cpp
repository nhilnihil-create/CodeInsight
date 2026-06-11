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
const int maxn=2e2+5;
ll k;
int len,n=0;
int a[maxn];
vector<int>A;
void pb(int x){
	a[++len]=x;
}
void pf(int x){
	++len;
	per(i,len,2)a[i]=a[i-1];
	a[1]=x;
}
int main(){
	read(k);k++;
	while(k)A.pb(k&1),k>>=1;
	reverse(A.begin(),A.end());
	rep2(i,1,SZ(A)){
		pb(++n);
		if(A[i])pf(++n);
	}
	rep(i,1,n)pb(i);
	printf("%d\n",len);
	rep(i,1,len)printf("%d ",a[i]);
	return 0;
}