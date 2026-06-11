#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
#define zeros(x) x^(x-1)&x
#define pii pair<ll,ll>
#define cd complex<double>
#define dbg(x) cerr<<x<<endl;
#define Nmax 500005
using namespace std;

ll n, mx, A, B, v[Nmax];

int main()
{
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> v[i];
        mx = max(mx, v[i]);
    }
    for (int i=1;i<=n;i++){
        if (v[i] == mx){
            B++;
        }
        else if (v[i] == mx-1) A++;
        else{
            cout << "No\n";
            return 0;
        }
    }
    if (A==0 && B == mx + 1){
        cout << "Yes\n";
        return 0;
    }
    if (B==1){
        cout << "No\n";
        return 0;
    }
    if (mx > A && mx <= A + B / 2) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
