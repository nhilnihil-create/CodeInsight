#include<bits/stdc++.h>
using namespace std;
struct node{
    int x;
	int qwq;
}a[100001];
bool cmp(node a,node b)
{
    return a.x<b.x;
}
int n,l,t,ans;
int main()
{
	cin>>n>>l>>t;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i].x>>a[i].qwq;
    	a[i].qwq--;
    }
    for(int i=1;i<=n;i++)
    	a[i].x=a[i].qwq?a[i].x-t:a[i].x+t,ans=a[i].x%l<0?ans+a[i].x/l-1:ans+a[i].x/l,a[i].x=(a[i].x%l+l)%l;
    sort(a+1,a+n+1,cmp);
    ans=(ans%n+n)%n;
    for(int i=ans+1;i<=n;i++)
    	cout<<a[i].x<<endl;
    for(int i=1;i<=ans;i++)
    	cout<<a[i].x<<endl;
    return 0;
}