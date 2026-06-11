#include <bits/stdc++.h>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
typedef long long ll;
typedef long double ld;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(void)
{
    ll N, i, A[100001], ans=0;

    cin >> N;

    for(i=1; i<=N; i++){
        cin >> A[i];
    }

    ans += (A[1]/2);
    A[1] %= 2;

    ll judge;

    for(i=2; i<=N; i++){
        ans += min(A[i-1],A[i]);
        A[i] -= min(A[i-1],A[i]);
        ans += (A[i]/2);
        A[i] %= 2;
    }

    cout << ans << endl;

    return 0;
}