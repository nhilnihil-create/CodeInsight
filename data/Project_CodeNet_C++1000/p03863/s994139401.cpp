#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) std::cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) std::cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) std::cout << x << endl;
#define println(x) std::cout << x << endl;
using namespace std;
// using namespace atcoder;
void Main()
{
    string s;
    cin >> s;

    if (s.size() % 2 == 0 && s[0] == s[s.size() -1]) {
        put("First");
    }
    else if (s.size() % 2 == 1 && s[0] != s[s.size() - 1]) {
        put("First");
    }
    else {
        put("Second");
    }
    
}
signed main(){ Main();return 0;}