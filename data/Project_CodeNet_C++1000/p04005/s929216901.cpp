#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 1000+20
#define ll long long
ll a[4];
int main()
{
	int flag = 1;
	cin >> a[0]>>a[1]>>a[2];
	sort(a, a + 3);
	for (int i = 0; i < 3; i++)
	{
		if (!(a[i] % 2))
		{
			flag = 0;
			break;
		}
	}
	if (flag)
		cout << a[0] * a[1] << endl;
	else
		cout << 0 << endl;
}