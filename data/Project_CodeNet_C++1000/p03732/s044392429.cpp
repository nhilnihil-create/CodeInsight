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

int isPrime(int a) {
    for (int i = 2; i * i <= a; ++i) {
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;
}





void oneCase () {
    int n, w;
    cin >> n >> w;
    vector<int> wgt(n);
    vector<int> val(n);
    for (int i = 0; i < n; ++i) {
        cin >> wgt[i] >> val[i];
    }
    map<ll, ll> maxVal;
    maxVal[0] = 0;
    for (int sub = 0; sub < n; ++sub) {
        map<ll, ll> newMax;

        for (auto p : maxVal) {
            auto weight = p.first;
            auto cost = p.second;
            if (newMax.count(weight) == 0) {
                newMax[weight] = cost;
            } else {
                newMax[weight] = max(cost, newMax[weight]);
            }

            if (weight + wgt[sub] > w) {
                continue;
            }
            if (newMax.count(weight + wgt[sub]) == 0 ) {
                newMax[weight + wgt[sub]] = cost + val[sub];
            } else {
                newMax[weight + wgt[sub]] = max(newMax[weight + wgt[sub]], cost + val[sub]);
            }
        }


        swap(maxVal, newMax);
    }
    ll best = 0;
    for (auto p : maxVal) {
        if (p.first <= w) {
            best = max(best, p.second);
        }
    }
    cout << best << "\n";

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