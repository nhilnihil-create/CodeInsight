#include<iostream>
#include<algorithm>
using namespace std;
int a[100001];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
		cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
		if(i+1>a[i+1])
		{
			int sum=0;
			for(int j=i+1;a[j]==i;j++)
				sum++;
			if(sum%2||(a[i]-i)%2)cout<<"First";else cout<<"Second";
			return 0;
		}
}