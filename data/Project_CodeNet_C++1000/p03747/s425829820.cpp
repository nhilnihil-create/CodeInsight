#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,L,t,a[N],num;
int main()
{
	int i,x,y;
	cin>>n>>L>>t;
	for(i=0;i<n;i++){
		scanf("%d %d",&x,&y);
		x+=(y==1 ? t : -t);
		(num+=x/L)%=n,x%=L;
		if(x<0) x+=L,num--;
		a[i]=x;
	  }
	sort(a,a+n);
	for(i=0;i<n;i++)
		printf("%d\n",a[(i+num+n)%n]);
	return 0;
}
