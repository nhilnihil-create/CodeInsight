#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

int main() {
    int bells[3];
    rep(0, 3) cin >> bells[i];

    sort(bells, bells + 3);

    cout << (bells[0] + bells[1]) << endl;

    return 0;
}
