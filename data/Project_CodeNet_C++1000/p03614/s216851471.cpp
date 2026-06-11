#include<iostream>
using namespace std;
int a[100005];
int swap(int a[],int n,int m)
{
	int t;
	t=a[n];
	a[n]=a[m];
	a[m]=t;
}
int main()
{
	int n,i,j;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int count=0;
	for(i=0;i<n;)
		for(j=i;j<n;j++)
			{
				if(a[j]==j+1)
					{
					swap(a,j,j+1);
					count++;
					}
				i++;
			}
	cout<<count;
}