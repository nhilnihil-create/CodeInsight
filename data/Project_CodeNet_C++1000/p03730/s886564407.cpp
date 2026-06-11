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
    int a, b, c;
    cin >> a >> b >> c;
    // A * N mod B = C
    // a1 = A mod B
    // a2 = (a1 + A) mod B

    int x = a % b;
    rep(i, b) {
        if (x == c) {
            put("YES");
            return 0;
        }
        x = (x + a) % b;
    }

    put("NO")
    return 0;
}