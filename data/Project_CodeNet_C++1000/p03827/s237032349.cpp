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

int gcd(int a, int b) {
    if(a % b == 0) {
        return b;
    }
    else {
        return(gcd(b, a % b));
    }
}


int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0, a = 0;
    rep(i, n) {
        if (s.at(i) == 'I') a++;
        else a--;
        ans = max(a, ans);
    }
    cout << ans << endl;
}