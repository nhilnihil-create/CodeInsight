#include<bits/stdc++.h>
using namespace std;
	int a[100000]={0};
int main()
{
	int n;
	cin>>n;
int count=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
		for(int i=1;i<=n;i++)
		{  int t;
			if(a[i]==i)
			 {
			 	t=a[i];
			 	a[i]=a[i+1];
			 	a[i+1]=t;
			 	count++;
			 }
		}
		cout<<count<<endl;
}