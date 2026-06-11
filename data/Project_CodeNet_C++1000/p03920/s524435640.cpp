#include<iostream>
#include<string>
#include<algorithm>	
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#define int long long
using namespace std;
int aa[123456];
signed main() {
    int n, sum = 0, a = 0, b = 0; cin >> n;
    for (int h = 0; h < 100000; h++) {
        sum += h;
        if (sum >= n) { a = h; break; }
    }
    sum = n;
    for (int h = a; h > 0; h--) {
        if (sum >= h) { sum -= h; aa[b] = h; b++; }
    }
    sort(aa, aa + b);
    for (int h = 0; h < b; h++) {
        cout << aa[h] << endl;
    }
}