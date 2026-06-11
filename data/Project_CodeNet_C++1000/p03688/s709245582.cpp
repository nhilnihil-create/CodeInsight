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
template<typename T> void chkmin(T &x,T y){x=x<y?x:y;}
int co[100010];

int main(){
	int n;read(n);
	int a=INT_MAX;int k=0;
	rep(i,1,n){read(co[i]);chkmin(a,co[i]);}
	a++;
	rep(i,1,n){
		k+=(co[i]==a-1);
		if(co[i]!=a-1&&co[i]!=a){puts("No");return 0;}
	}
	
	if(k==n){
		puts((a==n||(1<=a-1&&a-1<=n/2))?"Yes":"No");
	}else{puts((k+1<=a&&a<=k+(n-k)/2)?"Yes":"No");}
	return 0;
}
