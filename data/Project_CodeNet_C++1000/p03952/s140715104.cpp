#include <bits/stdc++.h>

#define pb push_back

using namespace std;

int n, x;
int used[2000005];
vector <int> ans;

int main () {
    cin >> n >> x;
    if (n == 2 && x == 2) {
        cout << "Yes\n" << 1 << '\n' << 2 << '\n' << 3;
        exit (0); 
    }
    if (x == 1 || x == n * 2 - 1) {
        cout << "No";
        exit (0);
    }cout << "Yes\n";
    used[1] = used[n * 2 - 1] = used[x] = 1;
    int cnt = 0;
    for (int i = 2;i < n * 2;i ++) {
        if (!used[i]) {
            cnt ++;
            cout << i << ' ';
            if (cnt == n - 2) {
                cout << 1 << ' ' << x << ' ' << n * 2 - 1 << ' ';
           }
        }
    }
}
