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
    int a, b;
    cin >> a >> b;
    if (a == 1) a = 14;
    if (b == 1) b = 14;
    if (a > b) cout << "Alice" << endl;
    else if (b > a) cout << "Bob" << endl;
    else cout << "Draw" << endl;
}