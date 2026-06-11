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

int gcd(int a, int b) {
    if(a % b == 0) {
        return b;
    }
    else {
        return(gcd(b, a % b));
    }
}


int main() {
    int a, b, c;
    int ans = 3;
    cin >> a >> b >> c;
    if (a == b) ans--;
    if (b == c) ans--;
    if (c == a) ans--;
    if (a == b && b == c) ans++;
    cout << ans << endl;
}