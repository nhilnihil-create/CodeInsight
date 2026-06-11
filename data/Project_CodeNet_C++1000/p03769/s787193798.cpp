#include<bits/stdc++.h>
using namespace std;
int a[105],b[105];
long long n;
int main(){
	cin>>n;n++;
	int m=100,p1=0,p2=0;
	while(n>1){
		if(n&1) a[++p1]=m--,n--;
		else b[++p2]=m--,n>>=1;
	}
	printf("%d\n",p1+p2<<1);
	for(int i=1;i<=p1;i++){
		printf("%d ",a[i]);
	}
	for(int i=p2;i>=1;i--){
		printf("%d ",b[i]);
	}
	for(int i=100-p1-p2+1;i<=100;i++){
		cout<<i<<" ";
	}
	return 0;
}