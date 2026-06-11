#include <bits/stdc++.h>
using namespace std;

inline void prnt(string msg="No") {
    cout << msg << "\n";
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; ++i) cin >> v[i];

    sort(v.begin(), v.end());
    if(v.front() == v.back()) {
        if(n == v.front()+1) prnt("Yes");
        else if(n < 2*v.front()) prnt();
        else prnt("Yes");
    }
    else {
        int cnt = count(v.begin(), v.end(), v.front());
        if(cnt > v.front()) prnt();
        else {
            int c = v.back() - cnt;
            int ncnt = n - cnt;
            if(ncnt < 2 * c) prnt();
            else prnt("Yes");
        }
    }

    return 0;
}
