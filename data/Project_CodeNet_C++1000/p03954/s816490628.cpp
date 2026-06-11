#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+4;
const int INF = 1e8+54;
int n;
int a[2*N];
int b[2*N];
bool check(int val)
{
	int pos1 = INF,pos2 = -INF;
	for(int i=1;i<=2*n-1;i++)
	{
		b[i] = (a[i] >= val);
//		cout<<b[i]<<" ";
	}
//	cout<<"\n";
	for(int i=n;i<=2*n-1;i++)
	{
		if(b[i] == b[i+1])
		{
			pos1 = i;
			break;
		}	
	}
	
	for(int i=n;i>=1;i--)
	{
		if(b[i] == b[i-1])
		{
			pos2 = i;
			break;
		}
	}
	
	if(pos1 == INF && pos2 == -INF)
	{
		if(n % 2 != 0)
			return b[n];
			
		else
			return (b[n] ^ 1);
	}
			
	if(pos1-n+1 < n-pos2+1)
		return b[pos1];
		
	else
		return b[pos2];
	
}

int main()
{
	cin>>n;
	for(int i=1;i<=2*n-1;i++)
	{
		scanf("%d",&a[i]);
	}
	
	int l=1,r=2*n-1;
	while(l < r)
	{
		int mid = (l+r+1)/2;
//		cout<<mid<<"\n";
		if(check(mid) == 1) l = mid;
		else r = mid-1; 
	}
	
	cout<<l;
}