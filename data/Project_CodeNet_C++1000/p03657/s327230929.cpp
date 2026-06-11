#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int a,b;
    cin >> a >> b;
    int c[3] = {a,b,a+b};
    bool ok = 0;
    rep(i,3) if(c[i]%3==0)ok = 1;
    if(ok)cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}
