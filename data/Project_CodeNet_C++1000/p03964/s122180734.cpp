#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

int n, a, b;
ll A, B;

int main() {
    cin >> n;
    A = B = 1;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        A = (A % a == 0 ? A : A + a - A % a);
        B = (B % b == 0 ? B : B + b - B % b);
        if (A / a * b > B) {
            B = A / a * b;
        }
        if (B / b * a > A) {
            A = B / b * a;
        }
    }
    cout << A + B << endl;
    return 0;
}
