#include <bits/stdc++.h>
using namespace std;

#define int long long
const double PI = 3.14159265358979323846;
typedef vector<int> vint;
typedef pair<int, int> pint;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
// cout << fixed << setprecision(20);

// 最大公約数
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int N;
int A[110000];
signed main() {
    cin >> N;
    for (int i = 0; i < N; i++)cin >> A[i];
    if (N == 1) {
        if (A[0] % 2 == 0)cout << "First" << endl;
        else cout << "Second" << endl;
        return 0;
    }
    if (N % 2 == 0) {
        int sum = 0;
        for (int i = 0; i < N; i++)sum += A[i];
        if (sum % 2 == 0)cout << "Second" << endl;
        else cout << "First" << endl;
        return 0;
    }

    string winner = "First";
    while (true) {
        int sum = 0;
        for (int i = 0; i < N; i++)sum += A[i];
        if (sum % 2 == 0) {cout << winner << endl; return 0;}

        winner = winner == "First" ? "Second" : "First";

        for (int i = 0; i < N; i++) {
            if (A[i] == 1) {cout << winner << endl; return 0;}
        }

        int odd = 0;
        for (int i = 0; i < N; i++)odd += A[i] % 2;
        if (odd != 1) {cout << winner << endl; return 0;}
        int g = A[0] % 2 == 0 ? A[0] : A[0] - 1;
        for (int i = 0; i < N; i++) {
            if (A[i] % 2 == 1)A[i]--;
            g = gcd(g, A[i]);
        }
        for (int i = 0; i < N; i++)A[i] /= g;

    }
}
