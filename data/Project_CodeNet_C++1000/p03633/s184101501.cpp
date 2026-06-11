#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include <queue>
using namespace std;
using ll = long long;

int N;
ll T[110];

ll gcd(ll x, ll y) {
	if (x % y == 0) {
        return y;
    } else {
        return gcd(y, x % y);
    }
}

ll lcm(ll x, ll y) {
    ll g = gcd(x, y);
    g = x / g * y;
    return g;
}


int main(void){

    ll ans = 0;

    cin >> N;
    for (int i = 1; i <= N;i++) cin >> T[i];

    ans = T[1];
    for (int i = 1; i < N;i++){
        ll com = T[i+1];
        ll L = lcm(ans,com);
        ans = L;
    }

    cout << ans << endl;

    return 0;
}
