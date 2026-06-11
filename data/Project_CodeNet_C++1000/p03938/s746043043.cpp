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

ll n,A[Nmax],B[Nmax],x;

int main()
{
    cin >> n;
    for (int i=1;i<=n;i++){
        A[i] = n * i;
        B[i] = n * (n-i+1);
    }
    for (int i=1,nr = n-1;i<=n;i++,nr--){
        cin >> x;
        B[x] -= nr;
    }
    for (int i=1;i<=n;i++) cout << A[i] << ' ';
    cout << '\n';
    for (int i=1;i<=n;i++) cout << B[i] << ' ';

    return 0;
}
