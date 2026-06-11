#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<map>
#include<iomanip>
#define rip(i,n) for(int i=0;i<n;i++)
#define ll long long
#define ld long double
#define set setprecision　//小数点以下何位まで知りたいか
#define mod 1000000007
#define pi 3.14159265
#include<numeric>
using namespace std;
int gcd(int a, int b)//最大公約数
{
	if (a % b == 0)	return(b);
	else return(gcd(b, a % b));
}
int lcm(int a, int b)//最小公倍数
{
	return a * b / gcd(a, b);
}
ll pow(ll a, ll b) {
	ll k = b % 30000, h = b / 30000, s = 1;
	rip(i, 30000)s = (s * a) % 2019; ll j = 1;
	if (h != 0)rip(i, h)j = j * s % 2019;
	if (k != 0)rip(i, k)j = j * a % 2019;
	return(j);
}
int main() {
	int n, l;
	cin >> n >> l;
	vector<int>a(n);
	rip(i, n)cin >> a[i];
	int maxx = 0;
	int k = 0;
	rip(i, n - 1) {
		maxx = max(maxx, a[i] + a[i + 1]);
		if (maxx ==a[i] + a[i + 1])k = i;
	}
	if (maxx < l)cout << "Impossible" << endl;
	else {
		k++;
		cout << "Possible" << endl;
		for (int i = 1; i < k; i++)cout << i << endl;
		for (int i = n - 1; i > k; i--)cout << i << endl;
		cout << k << endl;
	}
}