#include <bits/stdc++.h>
#define sz size
#define pb push_back
#define mper make_pair
#define PI 3.14159
#define F first
#define S second
#define ll long long
//#define forik(i, a, b) for(ll i = a; i <= b; ++i)
#define vl vector<ll>
#define pll pair<ll, ll>
//#define mal ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
using namespace std;

ll f(ll n, ll x) {

    if(n % x == 0) {

        return (n * 2ll) - x;

    }

    else {

        ll N = n - (n % x);

        return (N * 2) + f(x, n % x);

    }

}

int main() {

ll n, x;

cin >> n >> x;

cout << f((n - x), x) + n;


return 0;
}
