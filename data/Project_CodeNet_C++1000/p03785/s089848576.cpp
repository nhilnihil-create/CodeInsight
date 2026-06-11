#include <bits/stdc++.h>
using namespace std;
const int maxn=5000001,INF=1e9;
int n,m,k,c,now,d,pos,siz,car,a[maxn];
int main() 
{
	cin>>n>>c>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	pos=a[1]+k;siz=1;
	for(int i=1;i<=n;)
	{
		//cout<<"in "<<i<<endl;
		while(a[i+1]<=pos&&i+1<=n&&siz+1<=c)
		{
			i++,siz++;
		//	cout<<i<<" "<<siz<<endl;
		}
		if(i>n)break;
		i++;car++;pos=a[i]+k;siz=1;
	//	cout<<i<<" "<<car<<" "<<pos<<endl;
	}
	cout<<car;
}
	
/*
意思就一堆线段，线段长度是k，然后每个点可以标记d个线段，求最少点数量
快快活活地贪心，总之总是要把人接上的，那么按照右端点排序，能接就接，不能接就走。

*/