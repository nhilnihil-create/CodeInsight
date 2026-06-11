// a

// thanks to http://labelray.top/2018/08/19/agc-012-c-tautonym-puzzle/
// coded myself

// S[t+1] = (len(t)+1) + S[t]
// S[2*t+1] = S[t] + [len(t)+1]

#include <iostream>

using namespace std;

long long N;

const int MAX = 200;
int lft[MAX];
int lp = 0;
int rigt[MAX];
int rp = 0;

int current = 100;

void solve(long long x) {
    if (x<=0) return;
    if (!(x&1)) {
        lft[lp++] = current--;
        solve(x-1);
    } else {
        rigt[rp++] = current--;
        solve(x/2);
    }
}

int main() {
    cin >> N;
    solve(N);
    cout << 2 * (lp + rp) << endl;
    for (int i=0; i<lp; i++) {
        cout << lft[i] << " ";
    }
    for (int i=rp-1; i>=0; i--) {
        cout << rigt[i] << " ";
    }
    for (int i=101-rp-lp; i<101; i++) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}