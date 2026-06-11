#include<bits/stdc++.h>

using namespace std;
#define int            long long
#define f(i,n)        for(int i=0;i<(n);++i)
#define fa(i,a,n)     for(int i=a;i<=(n);++i)
#define fd(i,a,n)     for(int i=a;i>=(n);--i)
#define tc 			  int t;cin>>t;f(testcase,t)
#define pii             pair<int,int>
void c_p_c() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

}
#define M 1000000007
int modexp(int x, int n)
{
	if (n == 0)
		return 1;
	else if (n % 2 == 0)
		return modexp((x * x) % M, n / 2);
	else
		return (x * modexp((x * x) % M, (n - 1) / 2)) % M;

}

int ha[100001];
int32_t main() {

	c_p_c();
	int n;
	cin >> n;
	int a[n];
	memset(ha, 0, sizeof(ha));
	f(i, n)
	{
		cin >> a[i];
		ha[a[i]]++;
	}
	if (n % 2 == 0) {
		bool flag = 1;
		f(i, n)
		if (ha[a[i]] != 2)
		{
			flag = 0;
			break;
		}
		if (flag == 0)
			cout << "0";
		else
			cout << modexp(2, n / 2);
	}

	else {
		if (ha[0] != 1)
		{
			cout << "0";
			ha[0] = 2;
			return 0;
		}
		else
			ha[0] = 2;
		bool flag = 1;
		f(i, n) {
			if (ha[a[i]] != 2)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 0)
			cout << "0";
		else
			cout << modexp(2, (n - 1) / 2);

	}



	return 0;
}
