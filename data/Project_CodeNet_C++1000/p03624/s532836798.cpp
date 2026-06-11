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
    unordered_set<char> us;
    rep(i, s.size()) us.emplace(s[i]);
    for (int ch = 'a'; ch <= 'z'; ch++) {
        if (us.count(ch) <= 0) {
            put((char)ch)
            return 0;
        }
    }
    
    put("None")
    return 0;
}