#include <bits/stdc++.h>
using namespace std;
long long a[100];
long long C[55][55];
void init()//排列数 
{
	 C[0][0]=1;
	 for(int i=1;i<=50;i++)
	 {
	 	C[i][0]=1;
	 	for(int j=1;j<=i;j++)
	 	   C[i][j]=C[i-1][j-1]+C[i-1][j];
	 }
}
int main()
{
	init();
	int n,A,B;
	cin>>n>>A>>B;
	for(int i=1;i<=n;i++)
	   cin>>a[i];
	sort(a+1,a+n+1);
	long long sum=0,ans=0;
	for(int i=n-A+1;i<=n;i++)
	   sum+=a[i];
    long long cot=0,tot=0;
    for(int i=n-A+1;i<=n;i++) if(a[i]==a[n-A+1]) cot++;
    for(int i=1;i<=n;i++) if(a[i]==a[n-A+1]) tot++;
    if(a[n]==a[n-A+1])//特判 
      for(int i=A;i<=B;i++)
         ans+=C[tot][i];
	else ans=C[tot][cot];
	printf("%lf\n%lld",(double)sum/A,ans);
	return 0;
} 