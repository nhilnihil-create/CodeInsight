#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    string s;
    cin >> s;
    string r = "";
    rep(i, s.size()) {
        if (s[i] == 'B') {
            if (r.size() >= 1){
                r = r.substr(0, r.size() - 1);
            }
        }
        else {
            r.push_back(s[i]);
        }
    }
    put(r)
    return 0;
}