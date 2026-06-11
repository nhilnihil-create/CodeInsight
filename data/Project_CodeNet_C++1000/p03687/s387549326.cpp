#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);

    string s;
    cin >> s;
    ll r = 1e9;
    {
        char c = s[0];
        if(all_of(s.begin(), s.end(), [&](auto &x) {return c == x;})) {
            cout << 0 << endl;;
            return 0;
        }

    }
    for(char c='a'; c<='z'; c++) {
        ll i;
        string t = s;
        for(i=0; ; i++) {
            bool ok = true;
            for(ll j=0; j<t.size()-1; j++)
                if(t[j] == c || t[j+1] == c)
                    t[j] = c;
                else
                    t[j] = '.', ok = false;
            t.erase(t.end()-1, t.end());
            if(ok) break;
        }
        r = min(r,  i);
    }
    cout << r+1 << endl;
}
