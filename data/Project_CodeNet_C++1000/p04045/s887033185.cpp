#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,k; cin >> n >> k;
    int arr[k];
    map <int,int> mp;
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
        mp[arr[i]] = 1;
    }
    bool ok = true;
    while(ok) {
        ok  = false;
        int x = n;
        while (x > 0) {
            if (mp[x%10]) {
                ok = true;
                break;
            }
            x /= 10;
        }
        if (ok) n++;
    }
    cout << n << endl;
}