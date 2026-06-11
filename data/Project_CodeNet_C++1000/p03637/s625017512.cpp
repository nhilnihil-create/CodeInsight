#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <random>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int) n; i++)

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    int mul4 = 0;
    int mul2 = 0;
    int mul1 = 0;
    rep(i,n) {
        cin >> a[i];
        if (a[i] % 4 == 0) {
            mul4++;
        } else if (a[i] % 2 == 0) {
            mul2++;
        } else {
            mul1++;
        }
    }
    if (mul2 != 0) mul1++;
    if (mul1 <= mul4+1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}