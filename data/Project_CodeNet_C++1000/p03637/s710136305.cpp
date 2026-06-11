#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;

const double pie = acos(-1.0);
const ll MOD = 1e9 + 7;

// 最大公約数
ll gcd(ll a, ll b)
{
   if (a%b == 0) {
       return(b);
   } else {
       return(gcd(b, a%b));
   }
}

// 最小公倍数
ll lcm(ll a, ll b){
   return a / gcd(a, b) * b;
}

//素数判定
bool is_prime(const unsigned n){
    switch(n){
        case 0: // fall-through
        case 1: return false;
        case 2: // fall-through
        case 3: return true;
    } // n > 3 が保証された
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(unsigned i = 5; i * i <= n; i += 6) {
        if(n % i     == 0) return false; // (6の倍数)-1
        if(n % (i+2) == 0) return false; // (6の倍数)+1
    }
    return true;
}

void solve() {
	ll n; cin >> n;
    ll four = 0, two = 0, none = 0;
	for(int i = 0; i < n; ++i){
		ll a; cin >> a;
		if(a % 4 == 0) four++;
		else if(a % 2 == 0) two++;
		else none++;
	}
	if(four+1 >= none && two == 0) cout << "Yes" << endl;
	else if(four >= none) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();
    return 0;
}
