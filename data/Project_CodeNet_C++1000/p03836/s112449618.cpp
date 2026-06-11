#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr long long MOD = 1000000007;
constexpr long long INF = 1LL << 60;
const long double PI = acosl(-1.0);
constexpr long double EPS = 1e-11;
template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
int main(){
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    for (ll i = 0; i < tx - sx; i++) cout << "R";
	for (ll i = 0; i < ty - sy; i++) cout << "U";
	for (ll i = 0; i < tx - sx; i++) cout << "L";
	for (ll i = 0; i < ty - sy; i++) cout << "D";
    cout << "L";
	for (ll i = 0; i < ty - sy+1; i++) cout << "U";
	for (ll i = 0; i < tx - sx+1; i++) cout << "R";
    cout << "D";
    cout << "R";
	for (ll i = 0; i < ty - sy+1; i++) cout << "D";
	for (ll i = 0; i < tx - sx+1; i++) cout << "L";
    cout << "U";
    cout << endl;
}