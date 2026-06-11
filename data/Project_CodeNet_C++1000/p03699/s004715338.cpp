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
    int n;
    int sum = 0;
    cin >> n;
    vector<int> s(n);
    vector<bool> ten(n, false);
    rep(i, n) {
        cin >> s.at(i);
        sum += s.at(i);
    }
    sort(s.begin(), s.end());
    rep(i, n) {
        if (s.at(i) % 10 == 0) {
            ten.at(i) = true;
        }
    }
    if (sum % 10 != 0) {
        cout << sum << endl;
        return 0;
    }
    else {
        rep(i, n) {
            if(!ten.at(i)){
                sum -= s.at(i);
                cout << sum << endl;
                return 0;
            }
        }
        cout << 0 << endl;
    }
}