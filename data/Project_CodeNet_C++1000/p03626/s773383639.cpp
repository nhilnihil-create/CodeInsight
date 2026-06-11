#include <iostream>
using namespace std;

const int MOD = 1000000007;

int main() {
    int N;
    string s1, s2;
    cin >> N >> s1 >> s2;

    long long res = 0;
    int i = 0;
    if (s1[0] == s2[0]) {
        res = 3;
        i++;
    } else {
        res = 6;
        i += 2;
    }

    while (i < N) {
        if (s1[i] == s2[i]) {
            if (s1[i - 1] == s2[i - 1]) {
                res *= 2;
            } else {
                res *= 1;
            }
            i++;
        } else {
            if (s1[i - 1] == s2[i - 1]) {
                res *= 2;
            } else {
                res *= 3;
            }
            i += 2;
        }
        res %= MOD;
    }

    cout << res << endl;
    return 0;
}