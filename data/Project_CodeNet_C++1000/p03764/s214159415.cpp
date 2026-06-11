#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

const int maxn = 1e5 + 10;
ll n , m , a[maxn] , b[maxn];
const int mod = 1e9 + 7;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<m;i++) cin >> b[i];		
	ll one = a[1] - a[0];
	ll last = one;
	for(int i=2;i<n;i++)
	{
		last = ((a[i] - a[i-1]) * i) + last;
		one += last;
	}
	ll two = b[1] - b[0];
	last = two;
	for(int i=2;i<m;i++)
	{
		last = ((b[i] - b[i-1]) * i) + last;
		two += last;
	}
	one %= mod;
	two %= mod;
	cout << one * two % mod;
}