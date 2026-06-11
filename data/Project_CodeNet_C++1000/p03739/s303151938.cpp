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
	int a[n];
	zip(i, 0, n)
	{
		cin >> a[i];
	}
	int pre[n];
	int pre2[n];
	pre[0] = a[0];
	pre2[0] = a[0];
	zip(i, 1, n)
	pre[i] = pre[i - 1] + a[i], pre2[i] = pre2[i - 1] + a[i];
	//Try two possibilities independently: even-length prefixes are positive
	//or odd-length prefixes are positive
	int ans1 = 0;
	/* case 1 :- if(i is even then sum should be positive...)*/
	int var = 0;
	zip(i, 0, n)
	{
		pre[i] = pre[i] + var;
		if (i % 2 == 0)
		{
			if (pre[i] <= 0)
			{
				ans1 += -1 * pre[i] + 1;
				var += -1 * pre[i] + 1;
				pre[i] = 1;


			}
		}
		else
		{
			if (pre[i] >= 0)
			{
				ans1 += pre[i] + 1;
				var -= (pre[i] + 1);
				pre[i] = -1;

			}
		}
	}
	/* case 2 :- if i is even sum should be negative...)*/
	int ans2 = 0;
	var = 0;
	zip(i, 0, n)
	{
		pre2[i] = pre2[i] + var;
		if (i % 2)
		{
			if (pre2[i] <= 0)
			{
				ans2 += -1 * pre2[i] + 1;
				var += -1 * pre2[i] + 1;
				pre2[i] = 1;

			}
		}
		else
		{
			if (pre2[i] >= 0)
			{
				ans2 += pre2[i] + 1;
				var -= (pre2[i] + 1);
				pre2[i] = -1;


			}
		}
	}
	//cout << ans1 << en << ans2 << en;
	int ans = min(ans1, ans2);
	cout << ans << en;
	return 0;
}

