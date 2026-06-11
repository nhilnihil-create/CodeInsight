#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	vector<int> used(100000,0);
	int a,b,c;
	cin >> a >> b >> c;
	int now = 1;
	int m = 1;
	for(int i = 1;i<2000;i++)
	{
		now = a*(m++);
		now %= b;
		if(now==c)
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
}
