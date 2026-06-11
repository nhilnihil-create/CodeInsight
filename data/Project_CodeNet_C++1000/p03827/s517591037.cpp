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
    int n;
    string  s;
    cin >> n >> s;
    int x = 0;
    int max_x = x;
    rep(i, s.size()) {
        if (s[i] == 'I') {
            x++;
        }
        if (s[i] == 'D') {
            x--;
        }
        max_x = max(max_x, x);
    }
    put(max_x)
    return 0;
}