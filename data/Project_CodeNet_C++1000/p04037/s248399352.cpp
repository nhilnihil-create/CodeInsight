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
int n,a[N];
int cmp(int x,int y){
	return x>y;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1,cmp);
	int jl=0;
	for(int i=1;i<=n;i++){
		if(a[i]>=i)jl=i;
	}
	int js=0;
	for(int i=jl;i<=n;i++){
		if(a[i]<jl)break;
		js++;
	}
	int h=((a[jl]-jl+1)%2);
	if(js%2==1&&h==1)puts("Second");
	else puts("First");
}