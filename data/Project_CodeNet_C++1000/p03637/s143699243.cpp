#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <map>
using namespace std;

#define INF 1e9
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int dev4 = 0;
    int odd = 0;
    rep(i, n) {
        cin >> a.at(i);
        if (a.at(i) % 2 != 0) odd++;
        if (a.at(i) % 4 == 0) dev4++;
    }
    if (odd + dev4 == n && odd > dev4 + 1) cout << "No" << endl;
     else if (odd + dev4 != n && odd > dev4) cout << "No" << endl;
    else cout << "Yes" << endl;
}