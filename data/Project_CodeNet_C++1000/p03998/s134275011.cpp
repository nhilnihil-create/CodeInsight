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
    vector<string> s(3);
    rep(i, 3) cin >> s[i];
    
    int turn = 0;
    while(true) {
        if (s[turn].size() <= 0) {
            put((char)('A' + turn));
            break;
        }
        int nxt = s[turn][0] - 'a';
        s[turn] = s[turn].substr(1);
        turn = nxt;
    }
    
    return 0;
}