#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define mp make_pair
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int h,w;
	cin>>h>>w;
	int n;
	cin>>n;
	int a[n],cnt = 0,k=0;
	int b[h][w];
	for(int i = 0;i <n ; i++)
		cin>>a[i];
	for(int i = 0; i<h; i++)
	{
		if(i&1)
			for(int j = w-1; j>=0; j--)
			{
				b[i][j] = k+1;
				cnt++;
				if(cnt==a[k])
				{
					cnt = 0;
					k++;
				}
			}
		else
		for(int j = 0; j<w; j++)
		{
			b[i][j] = k+1;
			cnt++;
			if(cnt==a[k])
			{
				cnt = 0;
				k++;
			}
		}
	}
	for(int i = 0; i<h; i++)
		for(int j = 0; j<w; j++)
			cout<<b[i][j]<<" \n"[j==w-1];
	return 0;
}