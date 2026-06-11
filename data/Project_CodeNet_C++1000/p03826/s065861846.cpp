
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a, b, c, d;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> c >> d;
    cout << max(a * b, c * d) << endl;

    return 0;
}

