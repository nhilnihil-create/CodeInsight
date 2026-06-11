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
    int N, c;
    string s, t;
    int a, i, j, k;

    cin >> N;
    cin >> s;
    cin >> t;

    a = 0;
    for (i = 0; i < N; i++) {
        c = 0;
        for (j= 0, k=i; k < N; j++, k++) {
            if (s[k] == t[j]) {
                c++;
            } else {
                break;
            }
        }
        if (k == N) {
            a = max({c, a});
            break;
        }
    }
    cout << 2*N - a << endl;
}
