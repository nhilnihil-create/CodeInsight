#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

int main() {
    int x, t;
    cin >> x >> t;

    cout << (x > t ? x - t : 0) << endl;

    return 0;
}
