#include<bits/stdc++.h>
using namespace std;

int main()
{
int n,an=INT_MAX,s;cin>>n;
int a[n];
for(int i=0;i<n;i++)cin>>a[i];
for(int k=-100;k<=100;k++)
{s=0;
	for(int i=0;i<n;i++)
	s+=(a[i]-k)*(a[i]-k);
	an=min(an,s);
}
cout<<an<<endl;


}

