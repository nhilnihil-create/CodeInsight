#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a, b; cin >> a >> b;
	int arr[a + 50], mi[a + 50];
	fill(mi, mi + a, 2147483647);
	for(int i=0; i<a; i++)
	{
		cin >> arr[i];
		if(i) mi[i] = mi[i - 1];
		mi[i] = min(mi[i], arr[i]);
	}
	int cnt = 1, now = 0;
	for(int i=1; i<a; i++)
	{
//		cout << arr[i] << ' ' << mi[i] << '\n';
		if(arr[i] - mi[i - 1] > now)
		{
			cnt = 1;
			now = arr[i] - mi[i - 1];
		}
		else if(arr[i] - mi[i - 1] == now) cnt ++;
	}
	cout << cnt << '\n';
}