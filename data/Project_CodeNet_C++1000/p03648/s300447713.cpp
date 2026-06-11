#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
ll x[maxn] , a[maxn];
int main()
{
	ll k , n = 50;
	cin >> k;
	for(int i = 0; i < n; i++)
	{
		x[i] = k / n;
		if(i < k % n)
			x[i]++;
		a[i] = k - x[i];
	}
	cout << n << endl;
	for(int i = 0; i < n; i++)
	{
		a[i] = (n + 1) * x[i] - k;
		while(x[i] != (k - x[i] + a[i]) / n)
			a[i]++; //, cout << a[i] << endl;
		while(x[i] == (k - x[i] + a[i]) / n)
			a[i]++;
		a[i]--;
		cout << a[i] << " ";
	}
}
