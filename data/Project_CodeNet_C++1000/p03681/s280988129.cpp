    #include <bits/stdc++.h>
    #define ll long long int
    #define ld long double
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
        int n, m;
        cin >> n >> m;

        if (abs(n - m) >= 2) {
            put(0);
            return 0;
        }

        ll MOD = 1000000007;
        ll N = 1;
        repi(i, n + 1) N = (N * i) % MOD;
        ll M = 1;
        repi(i, m + 1) M = (M * i) % MOD;

        if (abs(n - m) == 1) {
            // n! * m!;
            put((N * M) % MOD);
        }
        else {
                put(( ((2 * N) % MOD) * M) % MOD);
        }
        return 0;
    }
