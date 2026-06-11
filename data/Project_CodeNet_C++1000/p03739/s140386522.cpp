#include<cstdio>
#include<iostream>
using namespace std;
const int N = 1e5+10;
int n,a[N];
int main()
{
	cin>>n;
	for (int i = 0 ;i < n ;i++)
		cin>>a[i];

	long long ans = -1;
	for (int i = 0; i <= 1 ; i++)
	{
		long long sum = 0;
		long long cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (j%2 == i)
			{
				if (sum+a[j] <= 0)
				{
					long long dif = 1-sum;
					cnt+= abs(dif-a[j]);
					sum = 1;
				}
				else	sum+=a[j];
			}
			else
			{
				if(sum + a[j] >= 0)
				{
					long long dif = -1 - sum;
					cnt+= abs(dif - a[j]);
					sum = -1;
				}
				else	sum+=a[j];
			}
		}
		if (ans == -1) ans = cnt;
		else		   ans = min(ans,cnt);
	}
	cout<<ans<<endl;

return 0;
}