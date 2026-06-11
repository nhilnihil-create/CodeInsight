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
using namespace std;

ll N, x,ans[Nmax];

int main()
{
    cin >> N >> x;
    if (x==1 || x == 2 * N - 1){
        cout << "No\n";
        return 0;
    }

    for (int i=N, j = x;i>=1;i--, j--){
        if (j==0) j = 2*N-1;
        ans[i] = j;
    }
    for (int i=N+1, j = x+1;i<=2*N-1;i++,j++){
        if (j==2*N) j = 1;
        ans[i] = j;
    }
    cout << "Yes\n";
    for (int i=1;i<=2*N-1;i++) cout << ans[i] << '\n';

    return 0;
}
