#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define ll long long
#define double long double

using namespace std;

int main() {
    double q, h, s, d, n;
    cin >> q >> h >> s >> d >> n;
    //sort by value
    double prices[4] = {q, h, s, d};
    double litres[4] = {0.25, 0.5, 1, 2};
    pair<double, pair<double, double>> vpl[4];
    for (int i = 0; i < 4; i++) {
        vpl[i] = {prices[i]/litres[i], {prices[i], litres[i]}};
    }
    //sort
    sort(vpl, vpl + 4);
    ll price_to_pay = 0;
    for (int i = 0; i < 4; i++) {
        price_to_pay += (int)(n/vpl[i].second.second) * vpl[i].second.first;
        n = fmodl(n, vpl[i].second.second);
    }
    cout << price_to_pay;
}