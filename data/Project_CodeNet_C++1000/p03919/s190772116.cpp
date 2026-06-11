#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;

string t[30][30];

int main() {
    int h, w;
    cin >> h >> w;
    char a1 = 'A';
    int a2=0;
    rep(i, h) rep(j, w) {
        cin >> t[i][j];
        if (t[i][j] == "snuke") {
            a1 += j;
            a2 = i+1;
        }
    }
    cout << a1 << a2 << endl;
}
