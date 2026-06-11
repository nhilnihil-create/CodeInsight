#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

using namespace std;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef long double ld;

const ll SIZE = 1e6 + 10, MOD = 1e9 + 7;



int main() {
    fastInp;
    
    ll x;
    cin >> x;

    ll pr = 0, i = 1;
    while (true) {
        pr += i;
        if (pr >= x) {
            cout << i << "\n";
            return 0;
        }
        i++;
    }

    return 0;
}
