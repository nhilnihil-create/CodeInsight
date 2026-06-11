#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"yes":"no")<<endl;
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
    yorn(s.size() == us.size());
    return 0;
}