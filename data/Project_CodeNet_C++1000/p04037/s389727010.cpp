#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 21;

int n, k;
long long a[MAXN];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n, greater <int>());

    for(int i = 1; i <= n; i++) {
        if(a[i] <= i) {
            k = 0;
            while(a[i + k] == i)
                k++;

            if (k & 1 || (a[i - 1] - i) & 1)
                cout << "First" << '\n';
            else
                cout << "Second" << '\n';
            return 0;
        }
    }
}
