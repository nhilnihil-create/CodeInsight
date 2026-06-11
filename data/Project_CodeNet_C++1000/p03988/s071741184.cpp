#include<iostream>
#include<algorithm>
using namespace std;
int n,cnt[111],m=111,M;
main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a;cin>>a;
		cnt[a]++;
		if(m>a)m=a;
		if(M<a)M=a;
	}
	bool flag=M%2&&cnt[m]==2||M%2==0&&cnt[m]==1;
	for(int i=m+1;i<=M;i++)
	{
		flag&=cnt[i]>=2;
	}
	flag&=m*2>=M;
	cout<<(flag?"P":"Imp")<<"ossible"<<endl;
}