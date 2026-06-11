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
    int k, s;
    cin >> k >> s;
    
    int cnt = 0;
    rep(x, k+1) rep(y, k+1) {
        int z = s- x - y;
        if (0 <= z && z <= k) {
            cnt ++;
        }
    }

    put(cnt);
    return 0;
}