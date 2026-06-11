#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(j, m) for (int j = 0; j < (int)(m); j++)
#define rep2(i, l, n) for (int i = l; i < (int)(n); i++)


int main() {
    int N;
    cin >> N;
    int i = 1;
    while (i*2 <= N) {
        i *= 2;
    }
    cout << i << endl;
}

