#include<bits/stdc++.h>
using namespace std;
long long Cnt[1010];
int main()
{
	int N;
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		int Tmp=i;
		for(int j=2;j<=i;j++)
			while(Tmp%j==0)
			{
				Tmp/=j;
				Cnt[j]++;
				//cout<<i<<":"<<j<<"->"<<Cnt[j]<<endl;
			}
	}
	long long Ans=1ll;
	for(int i=2;i<=N;i++)
		Ans=Ans*(Cnt[i]+1ll)%1000000007;
	cout<<Ans<<endl;
	return 0;
}
