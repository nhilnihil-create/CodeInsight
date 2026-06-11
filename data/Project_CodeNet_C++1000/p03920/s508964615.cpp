#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define dump(val) cerr << __LINE__ << ":\t" << #val << " = " << (val) << endl

using namespace std;

typedef long long int lli;

int main() {
    lli N;
    cin >> N;
    for (lli i = N; i > 0; i--) {
        lli t = i * (i + 1) / 2;
        if (t == N) {
            cout << i << endl;
            N -= i;
        }
        else if (t < N) {
            cout << i + 1 << endl;
            N -= (i + 1);
        }
    }
    return 0;
}