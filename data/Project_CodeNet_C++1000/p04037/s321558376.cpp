#include<cstdio>
#include<algorithm>
const int N=1e5+3; 
int n,a[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	std::sort(a+1,a+1+n);
	for(int i=0;i<n;i++)if(a[n-i]==i){
	  int f;
	  for(f=i+1;a[n-f]>=i;f++);
	  return 0*puts((f-i+1&1)&&(a[n-i+1]-i+1&1)?"Second":"First");
	}
	for(int i=0;i<n;i++)if(a[n-i-1]<i+1&&a[n-i]>i)return 0*puts(a[n-i]-i&1?"Second":"First");
}