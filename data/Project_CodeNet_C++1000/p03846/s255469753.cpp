#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <numeric>
#include <algorithm>
#include <utility>


using std::cout;
using std::cin;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


ll gcd(ll a, ll b) {
    while (b != 0) {
        auto tmp = a;
        a = b;
        b = tmp % a;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}


void oneCase () {
    int n;
    cin >>n;
    vector<int> a(n);
    for (auto& e : a) {
        cin >> e;
    }
    vector<int> order(n);
    for (int i = 0; i < n; ++i) {
        order[i] = abs((n - i - 1 - i));
    }
    sort(order.begin(), order.end());
    sort(a.begin(), a.end());
    if (a != order) {
        cout << 0 << "\n";
        return;
    }
    int mod = 1e9 + 7;
    ll count = 1;
    for (int i = 0; i * 2 + 1 < n; ++i) {
        count = (count * 2) % mod;
    }
    cout << count << "\n";



}





int main() {
    int t = 1;
//    cin >> t;
    while (t > 0) {
        oneCase();
        --t;
    }

    return 0;
}