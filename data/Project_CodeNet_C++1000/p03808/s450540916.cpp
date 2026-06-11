#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double
#define zeros(x) x^(x-1)&x
#define pii pair<ll,ll>
#define cd complex<double>
#define dbg(x) cerr<<#x<<": "<<x<<endl;ll
#define Nmax 400005
#define OFF 100001
#define MOD 1000000007
using namespace std;

ll n, s, v[Nmax], d[Nmax], x, nr;

int main()
{
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> v[i];
        s += v[i];
    }
    x = n * (n+1) / 2;
    if (s % x){
        cout << "NO\n";
        return 0;
    }
    x = s / x;

    for (int i=0;i<n;i++){
        d[i] = x - (v[(i+1) % n] - v[i]);
        if (d[i] < 0 || d[i] % n){
            cout << "NO\n";
            return 0;
        }
        nr += d[i] / n;
    }
    if (nr != x) cout << "NO\n";
    else cout << "YES\n";


    return 0;
}
