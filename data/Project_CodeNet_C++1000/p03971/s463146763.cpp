#include <bits/stdc++.h>
using namespace std;
#define arep(i, x, n) for (int i = int(x); i < (int)(n); i++)
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9 + 7
using ll = long long;

int main() {
    int n;
    int a;
    int c;
    cin >> n >> a >> c;

    string s;
    cin >> s;

    string output[n];
    int sum = 0;
    int sumB = 0;
    rep(i, n) {
        if (s.at(i) == 'a') {
            if (sum < a + c) {
                output[i] = "Yes";
                sum++;
            } else {
                output[i] = "No";
            }
        } else if (s.at(i) == 'b') {
            if (sum < a + c && sumB < c) {
                output[i] = "Yes";
                sum++;
                sumB++;
            } else {
                output[i] = "No";
            }
        } else {
            output[i] = "No";
        }
    }

    rep(i, n) { cout << output[i] << endl; }
}