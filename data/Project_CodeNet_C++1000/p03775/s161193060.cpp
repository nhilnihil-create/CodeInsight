#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define ff first
#define ss second
#define file_se_input  freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define pp long long int
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define pb push_back
#define mp make_pair
#define pi 3.141592653589793238
#define eb emplace_back
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define zip(i,a,b) for(int i=a;i<b;i++)
#define rzip(i,a,b) for(int i=a;i>=b;i--)
#define ll unsigned long long int
#define test int t;cin>>t; while(t--)
#define um unordered_map
#define en '\n'
#define us unordered_set
typedef pair<int, int>     pii;
typedef pair<char, int>    pci;
typedef pair<char, char>   pcc;
typedef vector<pii>       vii;
typedef long double ld;
#define all(v) v.begin(), v.end()
#define INF (1e18+5)
#define inf (1e9+5)
#define mod 1000000007


bool check_prime(long long n)
{
	int flag = 0;
	for (long long i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			flag = 1;
			break;
		}
	}
	if (n == 1)
		return false;
	else if (flag == 0 || n == 2 || n == 3)
	{
		return true;
	}
	else
	{
		return false;
	}

}

int BE(int x, int n, int m) //function to calculate x raise to power n modulo m
{
	int result = 1;
	while (n > 0)
	{
		if (n % 2 == 1)
			result = result * x % m;
		x = x * x % m;
		n = n / 2;
	}
	return result;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	if (fopen("input.txt", "r"))
	{
		freopen ("input.txt" , "r" , stdin);
		freopen ("output.txt" , "w" , stdout);
	}
#endif
	//_______________________________-code starts-_______________________________________________

	int n;
	cin >> n;
	int x = n;
	vi v;
	int ans = 1e9;
	rep(i, 1, sqrt(n))
	{
		if (n % i == 0)
		{
			string s1, s2;
			s1 = to_string(i);
			s2 = to_string(n / i);
			int var = max(s1.size(), s2.size());
			ans = min(ans, var);
		}
	}
	cout << ans << en;
	//sarasr galat approch its very easy maha gadha i am:)
	// while (x % 2 == 0)
	// {
	// 	x /= 2;
	// 	v.pb(2);
	// }
	// for (int i = 3; i <= sqrt(x); i += 2)
	// {
	// 	while (x % i == 0)
	// 	{
	// 		x /= i;
	// 		v.pb(i);
	// 	}
	// }
	// if (x > 2)
	// 	v.pb(x);
	// int var = 1;
	// int y = sqrt(n);
	// zip(i, 0, v.size())cout << v[i] << " "; cout << en;
	// // if (y * y == n)
	// // {
	// // 	string s = to_string(y);
	// // 	cout << s.size() << en;
	// // 	return 0;
	// // }
	// zip(i, 0, v.size())
	// {
	// 	if (n / v[i] >= y)
	// 	{
	// 		n = n / v[i];
	// 		var = var * v[i];
	// 	}
	// 	else
	// 	{
	// 		break;
	// 	}
	// }
	// cout << n << en << var << en;
	// string s1, s2;
	// s1 = to_string(n);
	// s2 = to_string(var);
	// cout << max(s1.size(), s2.size()) << en;


	return 0;
}

