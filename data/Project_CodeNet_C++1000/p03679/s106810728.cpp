#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;

#define INF 1e9
#define LLINF 1e18
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;


int main() {
    int x, a, b;
    cin >> x >> a >> b;
    if (b - a <= 0) {
        cout << "delicious" << endl;
    }
    else if (b - a > x) {
        cout << "dangerous" << endl;
    }
    else cout << "safe" << endl;
}