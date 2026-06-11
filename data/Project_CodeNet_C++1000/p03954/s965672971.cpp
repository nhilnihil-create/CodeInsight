#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define pci pair <char, int>
#define pld pair <ld, ld>
#define ppld pair <pld, pld>
#define ppll pair <pll, pll>
#define pldl pair <ld, ll>
#define vll vector <ll>
#define vvll vector <vll>
#define vpll vector <pll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mll map <ll, ll>
#define fastmap gp_hash_table
#define cd complex <double>
#define vcd vector <cd>
#define PI 3.14159265358979
#pragma 03
using namespace std;
using namespace __gnu_pbds;
// chctxdy
ll a[200005], e[200005];
ll n;
bool check(ll mid){
	for (ll i = 0; i < 2 * n - 1; i++) e[i] = (a[i] >= mid);
    for (ll i = 0; i < n - 1; i++){
        if (e[n - i - 1] == 0 && e[n - i - 2] == 0) return false;
        if (e[n + i - 1] == 0 && e[n + i] == 0) return false;
        if (e[n - i - 1] == 1 && e[n - i - 2] == 1) return true;
        if (e[n + i - 1] == 1 && e[n + i] == 1) return true;
    }
    if (e[0] == 0) return false;
    else return true;
}
void bs(){
    ll l = 1, r = 2 * n - 1;
    while (l < r){
    	ll mid = (l + r + 1) / 2;
    	if (check(mid)) l = mid;
    	else r = mid - 1;
	}
	cout << l << endl;
}
int main(){
	cin >> n;
    for (ll i = 0; i < 2 * n - 1; i++) cin >> a[i];
    bs();
    return 0;
}