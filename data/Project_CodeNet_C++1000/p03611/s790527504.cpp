#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    int i;
    for(i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), greater<int>());

    vector<int64_t> s(a[0]+3);
    for(i = 0; i < n; i++) {
        s[a[i]]++;
        s[a[i]+1]++;
        s[a[i]+2]++;
    }

    sort(s.begin(), s.end(), greater<int64_t>());

    cout << s[0] << endl;
}
