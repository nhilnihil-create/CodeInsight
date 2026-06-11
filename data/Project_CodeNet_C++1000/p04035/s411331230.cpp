#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();int s=0;
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		s=s*10+c-'0';c=getchar();
	}return s;
}
const int N=1e5+888;
int n,a[N],L,maxx,jl;
int main(){
	n=read();L=read();
	for(int i=1;i<=n;i++){a[i]=read();if(i>1){if(a[i-1]+a[i]>maxx)jl=i-1;maxx=max(maxx,a[i-1]+a[i]);}}
	if(maxx<L){
		puts("Impossible");return 0;
	}
	puts("Possible");
	for(int i=1;i<jl;i++)printf("%d\n",i);
	for(int i=n-1;i>jl;i--)printf("%d\n",i);
	cout<<jl;
	return 0;
}