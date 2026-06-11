#include<bits/stdc++.h>
using namespace std;
int n,a[100001],sum=0;
bool cmp(int x,int y){
	return x<y;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n,cmp);
	for(int i=2;i<=n;i++)
		if(a[i]==a[i-1]) sum++;
	if(sum%2==1) sum++;
	printf("%d\n",n-sum);
	return 0;
}