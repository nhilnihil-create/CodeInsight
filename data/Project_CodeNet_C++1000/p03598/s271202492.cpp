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
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    rep(i, n) cin >> x[i];
    
    int sum = 0;
    rep(i, n) {
        sum += min(2 * abs(x[i]), 2 * abs(k - x[i]));
    }
    put(sum)

    return 0;
}