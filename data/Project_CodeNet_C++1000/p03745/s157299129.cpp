#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define print(s) cout << s << endl
#define acc(v) accumulate(v.begin(), v.end(), 0)
#define cinv(n, v) rep(i, n) cin >> v[i]

using namespace std;
const int INF = 1e9;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vint;
typedef vector<string> vstr;
typedef vector<char> vchar;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;
int x_pos[4] = {1, 0, -1, 0}, y_pos[4] = {0, 1, 0, -1};
int ctoi(char c)
{
	if (c >= '0' && c <= '9')
	{
		return c - '0';
	}
	return 0;
}

char upper(char c)
{
	return c - 0x20;
}

char lower(char c)
{
	return c + 0x20;
}

void unique_vector(vector<int> &v)
{
	sort(all(v));
	v.erase(unique(all(v)), v.end());
}

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val)
{
	std::fill((T *)array, (T *)(array + N), val);
}

//ユークリッドの互除法
//最大公約数
ll gcd(ll x, ll y)
{
	if (y == 0)
		return x;
	return gcd(y, x % y);
}

//最小公倍数
ll lcm(ll x, ll y)
{
	ll g = gcd(x, y);
	return x / g * y;
}

ll myPow(ll x, ll n, ll m)
{
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return myPow(x * x % m, n / 2, m);
	else
		return x * myPow(x, n - 1, m) % m;
}

//k!
ll facctorialMethod(ll k)
{
	ll sum = 1;
	for (ll i = 1; i <= k; ++i)
	{
		sum *= i;
		sum %= MOD;
	}
	return sum;
}

//nCr
ll permutationMethod(ll n, ll r)
{
	ll n_sum, r_sum;
	r = n - r;
	n_sum = facctorialMethod(n);
	r_sum = facctorialMethod(r);
	return n_sum / r_sum;
}

// mod. m での a の逆元 a^{-1} を計算する
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

ll pow_kai(int a, int n)
{ //aのn乗を計算します。
	ll x = 1;
	while (n > 0)
	{ //全てのbitが捨てられるまで。
		if (n & 1)
		{ //1番右のbitが1のとき。
			x = (x * a) % MOD;
		}
		a = (a * a) % MOD;
		n >>= 1; //bit全体を右に1つシフトして一番右を捨てる。
	}
	return x % MOD;
}

int main()
{
	int n;
	cin >> n;
	int ans = 1;
	bool isUp = true;
	bool isFirst = true;
	ll before = 0;
	rep(i, n)
	{
		int a;cin>>a;
		if(i==0){
			before = a;
			continue;
		}
		if(before == a){
			continue;
		}
		if(isFirst){
			isUp = before < a ? true : false;
			before = a;
			isFirst = false;
			continue;
		}
		if((isUp && before > a)||
		(!isUp && before < a)){
			ans++;
			isFirst = true;
		}
		before = a;
	}
	cout << ans << endl;
}
