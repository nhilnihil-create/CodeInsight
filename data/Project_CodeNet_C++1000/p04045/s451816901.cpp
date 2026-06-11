#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    ios_base::sync_with_stdio(0);

    cin >> n >> k;
    vector<int> v(10);

    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        v[a]++;
    }

    while (true) {
        int f = 1;
        int temp = n;
        while (temp) {
            if (v[temp%10] == 1) {
                f = 0;
                break;
            }
            temp /= 10;
        }

        if (f) {
            cout << n;
            break;
        }

        ++n;
    }
}
