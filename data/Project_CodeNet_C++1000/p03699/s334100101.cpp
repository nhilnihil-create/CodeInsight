#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <cstdio>
#include <cmath>
#include <climits>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int) n; i++)
#define rep1(i, n) for(int i = 1; i <= (int) n; i++)
#define all(v) v.begin(),v.end()

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    int sum = 0;
    rep(i,n) {
        cin >> s[i];
        sum += s[i];
    }
    sort(all(s));
    if (sum % 10 == 0) {
        rep(i,n) {
            if (s[i] % 10 != 0) {
                sum -= s[i];
                break;
            }
        }
    }
    if (sum % 10 == 0) {
        cout << 0 << endl;
    } else {
        cout << sum << endl;
    }
    return 0;
}