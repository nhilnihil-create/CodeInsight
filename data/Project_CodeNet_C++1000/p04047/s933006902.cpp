#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
int x=2*n;
int a[x];
for(int i=0;i<x;i++)
cin>>a[i];
sort(a,a+x);
int sum=0;
for(int i=0;i<x;i+=2)
sum+=a[i];
cout<<sum<<endl;
}