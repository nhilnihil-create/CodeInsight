#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
using namespace std;
typedef long long ll;
 
int main() {
	ios::sync_with_stdio(false);
	int n, v[102] = {}, z = 0;
    ll W, w[102] = {};
    vector<int> a, b, c, d;
    cin >> n >> W >> w[0] >> v[0];
    a.push_back(v[0]);
    for (int i = 1; i < n; i++) {
        cin >> w[i] >> v[i];
        if (w[i] == w[0]) a.push_back(v[i]);
        else if (w[i] == w[0] + 1) b.push_back(v[i]);
        else if (w[i] == w[0] + 2) c.push_back(v[i]);
        else d.push_back(v[i]);
    }
    sort(a.begin(), a.end()); reverse(a.begin(), a.end());
    sort(b.begin(), b.end()); reverse(b.begin(), b.end());
    sort(c.begin(), c.end()); reverse(c.begin(), c.end());
    sort(d.begin(), d.end()); reverse(d.begin(), d.end());
    for (int i = 0; i <= a.size(); i++) {
        for (int j = 0; j <= b.size(); j++) {
            for (int k = 0; k <= c.size(); k++) {
                for (int l = 0; l <= d.size(); l++) {
                    if (w[0] * i + (w[0] + 1) * j + (w[0] + 2) * k + (w[0] + 3) * l <= W) {
                        int x = 0;
                        for (int m = 0; m < i; m++) x += a[m];
                        for (int m = 0; m < j; m++) x += b[m];
                        for (int m = 0; m < k; m++) x += c[m];
                        for (int m = 0; m < l; m++) x += d[m];
                        z = max(z, x);
                    }
                }
            }
        }
    }
	cout << z;
}