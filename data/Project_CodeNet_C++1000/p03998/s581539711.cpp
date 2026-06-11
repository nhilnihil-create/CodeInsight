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
    string a, b, c;
    int aa = 0, bb = 0, cc = 0;
    cin >> a >> b >> c;
    char before = 'a';
    char ans;
    while(true) {
        if (aa == a.size() && before == 'a') {
            ans = 'A';
            goto last;
        }
        else if (bb == b.size() && before == 'b') {
            ans = 'B';
            goto last;
        }
        else if (cc == c.size() && before == 'c') {
            ans = 'C';
            goto last;
        }
        if (before == 'a') {
            before = a.at(aa);
            aa++;
        }
        else if (before == 'b') {
            before = b.at(bb);
            bb++;
        }
        else if (before == 'c') {
            before = c.at(cc);
            cc++;
        }
    }
    last:
    cout << ans << endl;
}