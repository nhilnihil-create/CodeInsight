#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define all(v) ((v).begin()),((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define sz(v) ((int)(v).size())
#define clr(v, d)        memset(v, d, sizeof(v))
#define Fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
typedef long long ll;
const double PI = acos(-1.0);
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);// freopen("out.txt", "w", stdout);  
#endif
}
bool check_prime(ll a)
{
	bool flag = true;
	if (a <= 1)
		return false;
	else
	{
		for (ll i = 2; i <= sqrt(a); i++)
		{
			if (a % i == 0)
			{
				flag = false;
				break;
			}
		}
	}
	if (flag)
		return true;
	else
	{
		return false;
	}
}

int main()
{
	//file();
	Fast;
	ll n;
	cin >> n;
	int sum = 0;
	n = n * 2;
	vector<int>v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	if (n % 2 == 0)
	{
		for (int i = 0; i < n-1; i+=2)
		{
			sum += min(v[i], v[i + 1]);
		}
	}
	else
	{
		v.pop_back();
		for (int i = 0; i < n - 1; i += 2)
		{
			sum += min(v[i], v[i + 1]);
		}
	}
	cout << sum;
}