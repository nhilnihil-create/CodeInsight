#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()

using namespace std;
using ll = unsigned long long;
using pii = pair<int, int>;

const int oo = 1e9 + 7;
const ll mod = 1e9 + 7,maxn = 100000000;
const double PI = acos(-1);

ll fexp(ll base, ll p){
    ll ans = 1;

    while (p){
        if (p&1) ans*= base;
        base*=base;
        p >>= 1;
    }
    return ans;
}


int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    vector<pii> student(n), check(m);

    for (auto& it : student) cin >> it.ff >> it.ss;

    for (auto& it : check) cin >> it.ff >> it.ss;

    for (pii stu: student){
        int dist = oo, ans;
        for (int i=0; i<m; i++){
            if (abs(stu.ff - check[i].ff) + abs(stu.ss - check[i].ss) < dist){
                dist = abs(stu.ff - check[i].ff) + abs(stu.ss - check[i].ss);
                ans = i+1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}