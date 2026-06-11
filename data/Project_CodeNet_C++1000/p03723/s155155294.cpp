#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ll A, B, C;
    ll na, nb, nc;
    ll ans = 0;

    cin >> A >> B >> C;

    if (A == B && B == C && A % 2 == 0) {
        cout << -1 << endl; 
    } else {
        while (1) {
            if (A % 2 == 1 || B % 2 == 1 || C % 2 == 1) {
                break;
            }
            ans++;
            na = (B+C)/2;
            nb = (A+C)/2;
            nc = (A+B)/2;
            A = nb+nc;
            B = na+nc;
            C = na+nb;
        }
        cout << ans << endl;
    }
}
