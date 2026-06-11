#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	vector<int> p(n),a(20000),b(20000),ab(20000);
	for(int i = 0;i<20000;i++)
	{
		a[i] = 30000*i+1;
		ab[i] = 600000000;
		b[i] = ab[i] - a[i];
	}
	for(int i =0;i<n;i++)cin >> p[i];
	for(int i = 0;i<n;i++)
	{
		a[p[i]-1]+=i;
	}
	for(int i =0;i<n;i++)cout<<a[i]<<' ';cout<<endl;
	for(int i =0;i<n;i++)cout<<b[i]<<' ';cout<<endl;

}
