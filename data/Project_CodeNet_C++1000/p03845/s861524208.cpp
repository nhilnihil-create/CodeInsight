#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <deque>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>

#include <set>
#include <bitset>
#include<unordered_map>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
#define endl '\n'
#define exit(s) return cout<<s,0;
#define sz(s) (int)(s.size())
#define all(s) s.begin(),s.end()
#define allr(s) s.rbegin(), s.rend()
#define watch(x) cout << (#x) << " = " << x << endl
#define DNT ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
	ll n, m, sum = 0;
	cin >> n;
	vector<ll>v(n);
	for (int i = 0; i < n; i++) { cin >> v[i]; 
	
	sum += v[i];
	}
	cin >> m;
	while (m--)
	{
		ll x, y;
		cin >> x >> y;
		x--;
		cout << sum + (y - v[x]) << endl;
	}


	return 0;
}