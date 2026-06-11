#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n;
 cin>>n;
 int a[n];
 int i;
 int sum=0;
 for(i=0;i<n;i++)
 {
 cin>>a[i];
 sum+=a[i];
 }
 float m=1.0;
 m*=sum;
 m/=n;
 float x=m-floor(m);
 if(x>=0.5 && sum>=0)
 {
 	int p=m+1;
 	int ans1=0;
 	for(i=0;i<n;i++)
 	ans1+=pow(abs(a[i]-p),2);
 //	cout<<ans<<endl;
 	 p=m;
 	int ans2=0;
 	for(i=0;i<n;i++)
 	ans2+=pow(abs(a[i]-p),2);
 	cout<<min(ans1,ans2)<<endl;
 }
 else
 {
 	 		int p=m+1;
 	int ans1=0;
 	for(i=0;i<n;i++)
 	ans1+=pow(abs(a[i]-p),2);
 	 p=m;
 	int ans2=0;
 	for(i=0;i<n;i++)
 	ans2+=pow(abs(a[i]-p),2);
 	cout<<min(ans1,ans2)<<endl;
 }
 return 0;
}
