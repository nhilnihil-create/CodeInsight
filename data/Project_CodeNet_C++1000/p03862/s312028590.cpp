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
    ll N, x, i, a[100001], ans=0;

    cin >> N >> x;

    for(i=1; i<=N; i++){
        cin >> a[i];
    }

    if(a[1] > x){
        ans += (a[1]-x);
        a[1] = x;
    }

    for(i=2; i<=N; i++){
        if(a[i-1]+a[i] > x){
            ans += (a[i-1]+a[i]-x);
            a[i] = x-a[i-1];
        }
    }

    cout << ans << endl;

    return 0;
}