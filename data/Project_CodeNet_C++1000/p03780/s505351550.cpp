#include<string>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main()
{
int n,k,a[10000],cnt;
long long sum=0;
cin>>n>>k;
cnt=n;
for(int i=0;i<n;i++)
cin>>a[i];
sort(a,a+n);
reverse(a,a+n);
for(int i=0;i<n;i++)
{if(sum+a[i]<k)
 sum+=a[i];
 else
 cnt=n-i-1;}
cout<<cnt; 
system("pause"); 
return 0;
}