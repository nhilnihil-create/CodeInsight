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
    char a, b, ans;
    cin >> a >> b;
    if (a == 'H' && b == 'H') ans = 'H';
    else if (a == 'H' && b == 'D') ans = 'D';
    else if (a == 'D' && b == 'D') ans = 'H';
    else ans = 'D';
    cout << ans << endl;
}