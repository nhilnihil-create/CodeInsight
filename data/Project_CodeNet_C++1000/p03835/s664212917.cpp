#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
	int x,s;
	cin>>x>>s;
	int cnt=0;
	for(int i=0; i<=x; i++)
	{
		for(int j=0; j<=x; j++)
		{
			int k=s-i-j;
			if(k>=0 && k<=x) cnt++;
//			cout<<i<<' '<<j<<' '<<k<< endl;
		}
	}
	
	cout<<cnt;
	return 0;
}