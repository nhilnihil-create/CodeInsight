#include<bits/stdc++.h>
#define mo 1000000007
using namespace std;
int n,m,i,j,a[100005],x,y;
int read(){
	char ch=getchar();
	int xx=0;
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9'){
		xx=xx*10+ch-'0';
		ch=getchar();
	}
	return xx;
}
int main(){
	n=read();
	for(i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+n+1);
	if(a[n]-a[1]>=2){
		printf("No\n");
	}
	else if(a[n]-a[1]==1){
		for(i=1;i<n;i++)
			if(a[i]!=a[i+1]){
				x=i;
				break;
			}
		y=n-x;
		if(x+1<=a[n]&&a[n]<=x+y/2)
			printf("Yes\n");
		else
			printf("No\n");
	}
	else{
		if(a[1]==n-1||a[1]<=n/2)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}