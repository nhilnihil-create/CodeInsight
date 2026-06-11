#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define ddrep(i, n) for (int i = n; i > 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define ssrep(i, s, t) for (int i = s; i <= t; ++i)
#define chmax(x, y) (x = max(x, y))
#define chmin(x, y) (x = min(x, y))

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using ld = long double;
using str = string;

#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

long int M = 1e+9+7;
int inf = 1e+9;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << std::setprecision(10);

    int ans=0;
    vi abc(3),tmp(3);
    cin >> abc[0] >> abc[1] >> abc[2];
    sort(rng(abc));
    tmp[0] = abc[0];
    tmp[1] = abc[1];
    tmp[2] = abc[2];
    while(1){
        if(tmp[0]%2 || tmp[1]%2 || tmp[2]%2) break;
        ans++;
        int a=tmp[0];
        int b=tmp[1];
        int c=tmp[2];

        tmp[0] = b/2+c/2;
        tmp[1] = a/2+c/2;
        tmp[2] = a/2+b/2;
        sort(rng(tmp));
        bool flag = true;
        rep(i,3){
            if(!flag){
                flag=false;
                break;
            }
            if(abc[i]==tmp[i]) continue;
            flag=false;
        }
        if(flag){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}