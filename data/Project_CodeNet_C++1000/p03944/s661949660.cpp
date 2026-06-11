#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#define lowbit(x) ((x)&(-x))
#define sc scanf
#define debug(x) cout<<x<<" "
#define debug2(x) cout<<x<<"\n"
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
typedef long long ll;
const int inf=1<<30;
const int N=2e5+10;
using namespace std;
char s[1010][1010];
int gcd(int a,int  b){return b==0?a:gcd(b,a%b);}
int main()
{
	int w,h,n;
	cin>>w>>h>>n;
	int cnt1=0,cnt2=w,cnt3=0,cnt4=h;
	for(int i=0;i<n;i++)
	{
		int x,y,a;
		cin>>x>>y>>a;
		if(a==1)
		cnt1=max(x,cnt1);
		if(a==2)
		cnt2=min(x,cnt2);
		if(a==3)
		cnt3=max(y,cnt3);
		if(a==4)
		cnt4=min(y,cnt4);	
	}	
	int q=cnt4-cnt3,p=cnt2-cnt1;
	if(q<0||p<0)
	p=0;
	cout<<p*q<<"\n";
	return 0;
}