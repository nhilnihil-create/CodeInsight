#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

bool query(long long num) {
    cout << "? " << num << endl;
    
    string s; cin >> s;
    return s[0] == 'Y';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    if (!query(1000000000000000000LL)) {
        for (long long i = 1; ; i *= 10) {
            if (!query(i)) {
                long long st = i/10, ed = i-1;
                while (st < ed) {
                    long long md = (st+ed)/2;
                    if (query(md*10)) ed = md;
                    else st = md+1;
                }

                cout << "! " << st << endl;
                return 0;
            }
        }
    }

    else {
        for (long long i = 9; ; i *= 10) {
            if (query(i)) {
                cout << "! " << i/9 << endl;
                return 0;
            }
        }
    }

    return 0;
}