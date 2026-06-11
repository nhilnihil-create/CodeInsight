#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, a[N], c[N], Index;
long long ans = 0;

map <int, int> M;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> c[i], a[i] = c[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) M[a[i]] = i;
    for(int i = 1; i <= n; i += 2) if(M[c[i]] % 2 == 0) ans++;
    cout << ans << endl;
}

//如何避免假做法???