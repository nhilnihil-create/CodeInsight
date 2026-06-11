#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
template<typename T> void read(T &num){
	char c=getchar();T f=1;num=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	num*=f;
}
template<typename T> void qwq(T x){
	if(x>9)qwq(x/10);
	putchar(x%10+'0');
}
template<typename T> void write(T x){
	if(x<0){x=-x;putchar('-');}
	qwq(x);putchar('\n');
}
int a[100010];
inline bool cmp(int a,int b){
	return a>b;
}

int main(){
	int n;read(n);
	rep(i,1,n)read(a[i]);
	sort(a+1,a+n+1,cmp);
	
	int ll=1;int rr=n;int pos=0;
	while(ll<=rr){
		int mid=(ll+rr)>>1;
		if(a[mid]>=mid){pos=mid;ll=mid+1;}
		else{rr=mid-1;}
	}	
	
	int n1=(a[pos]-pos)%2;int n2=0;
	while(a[pos+n2+1]==pos)n2++;
	n2%=2;
	if(!(n1|n2)){puts("Second");}
	else{puts("First");}	
	return 0;
}