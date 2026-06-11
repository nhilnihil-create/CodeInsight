#include<bits/stdc++.h>
const int MN=10000+2;
using namespace std;
typedef long long ll;
template<typename T>T IN(T&in){
	in=0;char c=getchar();int f=1;
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))in=in*10+c-'0',c=getchar();
	in*=f;return in;
}
ll n;
int a[MN],L=100,R=L-1;
void input(){
	IN(n);n++;
	int p=40;
	while(!((1ll<<p)&n))p--;p--;
	while(p>=0){
		a[++R]=++a[0];
		if((1ll<<p)&n)a[--L]=++a[0];
		p--;
	}
	n=a[0];printf("%lld\n",n*2);
	for(int i=1;i<=n;++i)a[i]=a[i+L-1];
	for(int i=n+1;i<=n*2;++i)a[i]=i-n;
	for(int i=1;i<=n*2;++i)printf("%d ",a[i]);
}
int main(){
	
	input();
	return 0;
}