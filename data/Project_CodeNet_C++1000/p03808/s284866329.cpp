#include <bits/stdc++.h>
#include <boost/range/adaptors.hpp>
#include <boost/multiprecision/cpp_int.hpp>

/***** type *****/
using namespace std;
using ll = long long;
using ld = long double;
template <class T> using vt = vector<T>;
template <class T> using vvt = vector<vector<T>>;
template <class T> using vvvt = vector<vector<vector<T>>>;
using ml = boost::multiprecision::cpp_int;

/***** define *****/
#define all(c) (c).begin(), (c).end()            // begin to end
#define rep(i, b, e) for (ll i = b; i < e; i++)  // repeat
#define repr(i, b, e) for (ll i = b; e < i; i--) // repeat reverse
/***** const value *****/
#define llong_max 9223372036854775807            // 9 * 10^18
#define ldbl_max 1.79769e+308                    // 1.7 * 10^308
#define mod 1000000007                           // 1e9 + 7
#define pi 3.14159265                            // 3.14 ...
#define nyan 10                                  // nyan size
/***** for each macro *****/
#define fori(i, ...) if(ll i = -1) for(__VA_ARGS__) if(i++, true)
#define each(i, e, v) fori(i, auto& e: v)
#define forir(i, ...) if(ll i = Size(v)) for(__VA_ARGS__) if(i--, true)
#define eachr(i, e, v) forir(i, auto& e: boost::adaptors::reverse(v))

/***** lambda *****/
auto Fix = [] // fix value
(auto b, auto e, auto fix)
{ for (auto it = b; it != e; ++it) *it += fix; };
auto Bit = [] // long long bit shift
(auto n) { return (1LL << n); };
auto Count = [] // long long count value
(auto b, auto e, auto x) { return (ll)count(b, e, x); };
auto CtoN = [] // char to number
(auto c) { return (ll)(c - '0'); };
auto DivC = [] // long double div ceiling
(auto a, auto b) { return ceil((ld)a / (ld)b); };
auto NyaN = [] // long long nyan size
(auto n) { return (ll)pow(10, n); };
auto Size = []  // long long collection size
(auto& c) { return (ll)(c).size(); };
auto Sum = [] // long long accumulate
(auto b, auto e) { return accumulate(b, e, 0LL); };

/***** template *****/
template <class T> vvt<T> VVT
(ll ys, ll xs, T fill = T())
{	// vector<vector<T>> resize + fill
	vvt<ll> v(ys);
	each(i, y, v) { y.resize(xs, fill); } return v;
}
template <class T> vvvt<T> VVVT
(ll zs, ll ys, ll xs, T fill = T())
{	// vector<vector<vector<T>>> resize + fill
	vvvt<T> v(zs);
	each(i, z, v) { z = VVT(ys, xs, fill); } return v;
}
template <class T> vt<T> InputVT
(ll size, T fix = T())
{   // input vector<T> (T != struct) + fix
	vt<ll> v(size);
	each(i, e, v) { cin >> e; e += fix; } return v;
}
template <class T> vvt<ll> InputVVT
(ll ys, ll xs, T fix = T())
{   // input vector<vector<T>> (T != struct) + fix
	vvt<ll> v(ys); each(i, y, v) y.resize(xs);
	each(i, y, v) each(j, x, y){ cin >> x; x += fix; } return v;
}
template <class T> vvvt<ll> InputVVVT
(ll zs, ll ys, ll xs, T fix = T())
{	// input vector<vector<vector<T>>> (T != struct) + fix
	vvvt<ll> v(zs);
	each(i, z, v) { z = InputVVT<T>(ys, xs, fix); } return v;
}

int main(void)
{
	ll N; cin >> N;
	vt<ll> A = InputVT<ll>(N);

	if (Sum(all(A)) % (N * (N + 1) / 2) != 0)
	{
		cout << "NO";
		return 0;
	}

	ll ans = Sum(all(A)) / (N * (N + 1) / 2);
	each(i, e, A)
	{
		ll d = (i == N - 1) ? A[0] - A[i] : A[i + 1] - A[i];
		if ((ans - d) % N != 0 || ans - d < 0)
		{
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";
	return 0;
}
