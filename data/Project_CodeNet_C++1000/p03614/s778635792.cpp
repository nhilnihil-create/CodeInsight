#include<iostream>
using namespace std;
const int maxn=1e5+5;
int main()
{
	int n;
	scanf("%d",&n);
	int i,j;	
	int a[maxn],b[maxn]={0};
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int cnt=0;
	int t;
	for(i=0;i<n;i++){
		if(a[i]==i+1){
		t=a[i];
		a[i]=a[i+1];
		a[i+1]=t;
		cnt++;
		}
	}
	printf("%d\n",cnt);
}