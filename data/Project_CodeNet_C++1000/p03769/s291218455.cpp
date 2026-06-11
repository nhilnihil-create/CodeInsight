#include <iostream>
using namespace std;
int s[210];
int v[110];
int main()
{
	long long n;
	cin >> n;
	n ++;
	int ans = 0;
	int k = -1;
	while(n)

	{
		v[++ k] = n % 2;
		n /= 2;
	}
	for(int i = 1;i <= k;i ++)
		s[2 * i] = 1;
	for(int i = 0,j = 2 * k + 1;i < k;i ++,j -= 2)
		if(v[i])
			s[j] = 1;
	for(int i = 1;i <= 2 * k + 1;i ++)
		if(s[i])
			ans ++;
	cout << ans * 2 << endl;
	for(int i = 2 * k + 1;i > 0;i -= 2)
		if(s[i])
			cout << i << ' ';
	for(int i = 1;i <= k;i ++)
		cout << 2 * i << ' ';
	for(int i = 1;i <= 2 * k + 1;i ++)
		if(s[i])
			cout << i << ' ';
	cout << endl;
	return 0;
}