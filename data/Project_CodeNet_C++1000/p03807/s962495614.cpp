#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ll N;
    ll x;
    ll c = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (x % 2 == 1) {
            c++;
        }
    }

    if (c % 2 == 1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}
