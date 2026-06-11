#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<ctime>
using namespace std;
const int N=200010;
int n,a[N];
bool judge1(int x,int y,int z) {return ((a[x]>z) &&(a[y]>z));}
bool judge2(int x,int y,int z) {return ((a[x]<=z) && (a[y]<=z));}
bool check(int x)
{
	int i;
	for(i=0;i<n-1;i++)
	{
		if(judge1(n-i,n-i-1,x) || judge1(n+i,n+i+1,x)) return 0;
		if(judge2(n-i,n-i-1,x) || judge2(n+i,n+i+1,x)) return 1;
	}
	return judge2(1,1,x);
}
int main()
{
    int i,j,l,r,mid,ans;
    scanf("%d",&n),l=1,r=2*n-1;
    for(i=1;i<=2*n-1;i++) scanf("%d",&a[i]);
    while(l<=r)
    {
    	mid=l+r>>1;
    	if(check(mid)) ans=mid,r=mid-1;
    	else l=mid+1;
	}
	cout<<ans<<endl;
    return 0;	
} 