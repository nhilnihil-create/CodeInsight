#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	int i,n,s,j;
 	int m=INT_MAX;
 	cin>>n;
 	int a[n];
 	for(i=0;i<n;i++)
 		cin>>a[i];
	for(i=-100;i<=100;i++)
		{
			s=0;
			for(j=0;j<n;j++)
				{
					s+=pow(a[j]-i,2);
				}
			if(s<m)
			{
				m=s;
			}
		}
		cout<<m<<endl;
 }