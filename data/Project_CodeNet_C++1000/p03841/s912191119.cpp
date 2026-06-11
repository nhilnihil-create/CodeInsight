#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,a[N];
struct each{
	int a,b;
}b[N];
bool com(each x,each y){
	return x.a<y.a;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i].a);
		b[i].b=i,a[b[i].a]=i;
	}
	int now=1;
	sort(b+1,b+n+1,com);
	for(int i=1;i<=n;i++){
		for(int j=1;j<b[i].b;j++){
			while(now<=n*n&&a[now])	++now;
			if(now>b[i].a){
				puts("No");
				return 0;
			}
			a[now++]=b[i].b;
		}
	}

	now=n*n;
	for(int i=n;i;i--){
		for(int j=1;j<=n-b[i].b;j++){
			while(now<=n*n&&a[now])	--now;
			if(now<b[i].a){
				puts("No");
				return 0;
			}
			a[now--]=b[i].b;
		}
	}

	puts("Yes");
	for(int i=1;i<=n*n;i++)	printf("%d ",a[i]);
	return 0;
}