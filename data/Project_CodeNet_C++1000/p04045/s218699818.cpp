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
int n, k;
map<int, int>m1;

bool is_possible(int n)
{
	while (n > 0)
	{
		int x = n % 10;
		n /= 10;
		if (m1[x] > 0)
		{
			return false;
		}
	}
	return true;
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



	cin >> n >> k;
	int d[k];

	zip(i, 0, k)
	{
		cin >> d[i];
		m1[d[i]]++;
	}
	int min_number;
	rep(i, 0, 9)
	{
		if (m1[i] == 0)
		{
			min_number = i;
			break;
		}
	}
	string s = to_string(n);
	string t = s;
	int n1 = s.size();
	int var = 0;
	while (1)
	{
		if (is_possible(n))
			break;
		else
		{
			n++;
		}

	}
	cout << n << en;
	//cout << m1[1] << en;
	// zip(i, 0, n1)
	// {
	// 	int x = s[i] - '0';
	// 	// if (i == 0)
	// 	// {
	// 	// 	cout << x << en;
	// 	// }
	// 	if (m1[x] > 0 && var == 0)
	// 	{
	// 		while (m1[x] > 0)
	// 		{
	// 			x++;
	// 		}
	// 		s[i] = char(x + '0');
	// 		var++;
	// 	}
	// 	else if (var > 0 && m1[x] > 0)
	// 	{
	// 		s[i] = char(min_number + '0');
	// 	}
	// 	if(i==n-1&&s==t&&m1[x]>0)
	// 	{

	// 	}

	// 	// else if (m1[x] == 0 && var == 0 && i == n1 - 1)
	// 	// {
	// 	// 	x++;
	// 	// 	while (m1[x] > 0)
	// 	// 	{
	// 	// 		x++;
	// 	// 	}
	// 	// 	s[i] = char(x + '0');
	// 	// }
	// }
	//cout << s << en;

	return 0;
}

