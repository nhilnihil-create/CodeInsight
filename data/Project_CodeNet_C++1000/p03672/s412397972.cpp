#include <bits/stdc++.h>
using namespace std;
#ifdef ENABLE_DEBUG_OUTPUT
#define DEBUG_LOG(s) cout << s << endl;
#else
#define DEBUG_LOG(s) void();
#endif

int main(){
    string s;
    cin >> s;

    for (auto i = ((int)s.size() - 1) / 2; i > 0; i--) {
        // cout << s.substr(0, i) << " " << s.substr(i, i) << endl;
        if(s.substr(0, i) == s.substr(i, i)) {
            cout << 2*i << endl;
            return 0;
        }
    }

    return 0;
}