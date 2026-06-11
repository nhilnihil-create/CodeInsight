/*
Çé¿ö1
   1
  110
 01100
0011000
  ^^
Çé¿ö2
   0
  001
 10011
1100111
  ^^
Çé¿ö3
   1
  011
 00111
0010111
    ^^
Çé¿ö4
   0
  001
 00011
0001011
 ^^
Çé¿ö5 
   1
  101
 10101
1010101
^
Çé¿ö6
   0
  010
 01010
0101010
^
*/
#include<iostream>
using namespace std;

int n,a[20000010];
int l,r;

bool judge1(int k,int g,int h)
{return (a[g]>k)&&(a[h]>k);}
bool judge2(int k,int g,int h)
{return (a[g]<=k)&&(a[h]<=k);}
bool check(int x)
{
	for(int i=0;i<=n-2;i++)
	{
		if(judge1(x,n+i,n+i+1)||judge1(x,n-i,n-i-1))//1 3
			return 0;
		if(judge2(x,n+i,n+i+1)||judge2(x,n-i,n-i-1))//2 4
			return 1;
	}
	return judge2(x,1,1);//5 6
}

int main()
{
//	freopen("4.in","r",stdin);
	cin>>n;
	for(int i=1;i<=2*n-1;i++)
		cin>>a[i],r=max(r,a[i]);
	l=1;//r=2*n-1;
	while(l<r)
	{
//		cout<<l<<" "<<r<<endl;
		int mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<r<<endl;
//	for(int i=1;i<=n*2-1;i++)cout<<check(i);
}