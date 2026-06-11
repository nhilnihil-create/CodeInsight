#include<iostream>
#include<cstring>
#define MAXN 100010
using namespace std;
int n;
int A[MAXN];
bool state=0;
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
bool Judge()
{
	int odd=0,even=0;
	bool res=0,one=0;
	for(int i=0;i<n;i++)
	{
		if(A[i]&1)odd++;
		else even++,res^=1;
		if(A[i]==1)one=1;
	}
	if(one)return res;
	if(!even)return 0;
	else if(even&1)return 1;
	else
	{
		if(odd==1)
		{
			int g=0;
			for(int i=0;i<n;i++)
			{
				if(A[i]&1)A[i]--;
				g=gcd(g,A[i]);
			}
			for(int i=0;i<n;i++)A[i]/=g;
			return !Judge();
		}
		else
		{
			return 0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&A[i]);
	if(Judge())puts("First");
	else puts("Second");
 	return 0;
}
