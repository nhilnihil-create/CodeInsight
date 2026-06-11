#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    map<int, int> mp;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(a.begin(), a.end());
    if (a[a.size() - 1] != a[a.size() - 2]) {
        puts("Impossible");
        return 0;
    }
    else if ((a[a.size() - 1] & 1) && !(a[0] == a[1] && a[0] == a[a.size() - 1] / 2 + 1 && mp[a[0]] == 2)) {
        puts("Impossible");
        return 0;
    }
    else if (!(a[a.size() - 1] & 1) && !(a[0] == a[a.size() - 1] / 2 && mp[a[0]] == 1)) {
        puts("Impossible");
        return 0;
    }
    if (n & 1) {
        for (int i = a[a.size() - 1] / 2 + 2; i < a[a.size() - 1]; i++) {
            if (mp.find(i) == mp.end() || mp[i] < 2) {
                puts("Impossible");
                return 0;
            }
        }
    }
    else {
        for (int i = a[a.size() - 1] / 2 + 1; i < a[a.size() - 1]; i++) {
            if (mp.find(i) == mp.end() || mp[i] < 2) {
                puts("Impossible");
                return 0;
            }
        }
    }
    puts("Possible");
    return 0;
}