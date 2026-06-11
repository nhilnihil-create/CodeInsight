#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,h,w;
	scanf("%d%d%d%d",&n,&m,&h,&w);
	int k=1000000000/h/w;
	long long ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(i%h==0&&j%w==0)	ans-=(h*w-1)*k+1;
			else	ans+=k;
	if(ans<=0)	puts("No");
	else{
		puts("Yes");
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				if(i%h==0&&j%w==0)	printf("%d ",-(h*w-1)*k-1);
				else	printf("%d ",k);
			putchar('\n');
		}
	}
	return 0;
}