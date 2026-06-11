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
    string a, b, c, ans;
    cin >> a >> b >> c;
    ans += a.at(0) - 32;
    ans += b.at(0) - 32;
    ans += c.at(0) - 32;
    cout << ans << endl;
}