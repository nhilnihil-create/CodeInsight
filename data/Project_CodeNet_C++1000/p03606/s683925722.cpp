#include <iostream>
using namespace std;
using ll = long long int;
int main() {
    ll N;
    cin >> N;
    ll sum = 0;
    for (ll i = 0; i < N; i++) {
        ll li, ri;
        cin >> li >> ri;
        sum += (ri - li + 1);
    }
    cout << sum << endl;
}