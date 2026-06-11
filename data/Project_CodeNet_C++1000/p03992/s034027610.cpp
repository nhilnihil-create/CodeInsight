#define _GLIBCXX_DEBUG
typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

ll mod = 1000000007;

template<class Type> inline bool chmax(Type& a, Type b) { if (a < b) { a = b; return 1; } return 0; }
template<class Type> inline bool chmin(Type& a, Type b) { if (a > b) { a = b; return 1; } return 0; }

template<class Type>
Type modpow(Type a, Type n, Type mod)
{
	Type res = 1;
	while (0 < n)
	{
		if (n & 1)
		{
			res = res * a % mod;
		}
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

template<class Type>
Type gcd(Type x, Type y)
{
	Type r;
	if (x < y)
	{
		swap(x, y);
	}

	while (0 < y)
	{
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}

template<class Type>
bool isPrime(Type x)
{
	if (x == 2) return true;
	if (x < 2 || x % 2 == 0) return false;

	for (Type i = 3; i <= sqrt(x); i += 2)
	{
		if (x % i == 0) return false;
	}
	return true;
}

template<class Type>
vector<bool> eratos(Type n)
{
	vector<bool> isPrime(n + 1, true);
	isPrime[0] = isPrime[1] = false;
	for (Type i = 2; i <= n; i++)
	{
		if (isPrime[i])
		{
			Type j = i + i;
			while (j <= n)
			{
				isPrime[j] = false;
				j = j + i;
			}
		}
	}
	return isPrime;
}

bool binarySearchJudge(vector<int> a, int index, int key)
{
	if (key <= a[index]) return true;
	else return false;
}

int binarySearch(vector<int> a, int key)
{
	int ng = -1;
	int ok = a.size();
	while (1 < abs(ng - ok))
	{
		int mid = (ng + ok) / 2;
		if (binarySearchJudge(a, mid, key)) ok = mid;
		else ng = mid;
	}
	return a[ok] == key;
}

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < 4; i++)
	{
		cout << s[i];
	}
	cout << " ";
	for (int i = 4; i < s.size(); i++)
	{
		cout << s[i];
	}
	cout << endl;
}