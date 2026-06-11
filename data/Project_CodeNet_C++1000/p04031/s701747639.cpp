#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
 int ans ,sum=0 ,cost1=0 , cost2=0;
cin>>n;
int a[n];
for(int i=0; i<n; i++)
{
cin>>a[i];
sum=sum+a[i];
}
ans=sum/n;
for(int i=0; i<n; i++)
cost1=cost1+((a[i]-ans)*(a[i]-ans));
ans=(sum/n)+1;
for(int i=0; i<n; i++)
cost2=cost2+((a[i]-ans)*(a[i]-ans));

cout<<min(cost1,cost2);
return 0;
}

