#include <iostream>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    else if (b % a == 0) return a;
    else return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    if (a % b == 0) return a;
    else if (b % a == 0) return b;
    else return a / gcd(a, b) * b;
}
int main(void) {
    ll N;cin>>N;
    ll gen = 1;
    for (ll i = 1; i <= N; i++) {
        ll T;cin>>T;
        gen = lcm(gen, T);
    }
    cout << gen << endl;
    return 0;
}