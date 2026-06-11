#include<bits/stdc++.h>
using namespace std;
#define N 1111116

int n,m,a[N];

bool cmp(int x,int y){
	return x%2>y%2;
}

int read(){
	int x=0,f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-')  f=-f;
	for (;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main(){
	n=read();m=read();
	for (int i=1;i<=m;i++) a[i]=read();
	sort(a+1,a+m+1,cmp);
	if (a[3]%2){
		printf("Impossible\n");
		return 0;
	}
	if (a[2]%2) swap(a[2],a[m]);
	for (int i=1;i<=m;i++)
		printf((i!=m)?"%d ":"%d\n",a[i]);
	if (m==1){
		if (a[1]==1) printf("1\n1\n");
		else printf("2\n%d 1\n",a[1]-1);
	}
	else {
		a[1]++;a[m]--;if (!a[m]) m--;
		printf("%d\n",m);
		for (int i=1;i<=m;i++)
			printf((i!=m)?"%d ":"%d\n",a[i]);
	}
	return 0;
}