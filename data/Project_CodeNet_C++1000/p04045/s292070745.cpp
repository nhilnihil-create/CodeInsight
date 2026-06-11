#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    int k;

    cin >> n >> k;
    vector<int> v(10);

    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        v[a]++;
    }

    int t = 0;
    while (!t) {
        int temp = n;
        int f = 1;
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
        n++;
    }

    return 0;
}
