#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef long long ll;
const long long MOD = 1000000000 + 7;

int main(){
    int n;
    cin >> n;
    int l[n], r[n];
    rep(i, n) cin >> l[i] >> r[i];
    ll cnt = 0;
    rep(i, n)
    {
        cnt += r[i] - l[i] + 1;
    }
    cout << cnt << endl;
    return 0;
}