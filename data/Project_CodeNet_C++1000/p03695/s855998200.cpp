#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define sizeOf(A) (sizeof(A))/(sizeof(A[0]))
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);

int main() {
    fastio;

    int n;
    cin >> n;
    bool colors[8] = {};
    int others = 0;
    FOR(i, 0, n) {
        int x;
        cin >> x;
        if (x >= 1 && x <= 399) {
            colors[0] = true;
        } else if (x >= 400 && x <= 799) {
            colors[1] = true;
        } else if (x >= 800 && x <= 1199) {
            colors[2] = true;
        } else if (x >= 1200 && x <= 1599) {
            colors[3] = true;
        } else if (x >= 1600 && x <= 1999) {
            colors[4] = true;
        } else if (x >= 2000 && x <= 2399) {
            colors[5] = true;
        } else if (x >= 2400 && x <= 2799) {
            colors[6] = true;
        } else if (x >= 2800 && x <= 3199) {
            colors[7] = true;
        } else if (x >= 3200) {
            others++;
        }
    }
    int diffColors = 0;
    FOR(i, 0, 8) {
        if (colors[i]) {diffColors++;}
    }
    cout << max(1, diffColors) << " " << diffColors + others << "\n";
    return 0;
}
