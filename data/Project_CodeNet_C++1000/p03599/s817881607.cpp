#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    vi X;
    for (int i = 0; i < 31; i++) {
        for (int j = 0; j < 31; j++) {
            int w = 100 * A * i + 100 * B * j;
            if (w > F) continue;
            X.push_back(w);
        }
    }

    vi Y;
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            int s = C * i + D * j;
            if (s > F) continue;
            Y.push_back(s);
        }
    }

    int ares = 0;
    int bres = 0;
    double maxcon = -1;
    double econ = (double) E / ((double) 100 + (double) E);
    for (int i = 0; i < X.size(); i++) {
        for (int j = 0; j < Y.size(); j++) {
            int a = X[i];
            int b = Y[j];
            if (a + b > F) continue;

            double ncon = (double) b / ((double) a + (double) b);

            if (ncon <= econ) {
                if (maxcon < ncon) {
                    maxcon = ncon;
                    ares = a;
                    bres = b;
                }
            }
        }
    }
    cout << (ares + bres) << " " << bres << endl;
}