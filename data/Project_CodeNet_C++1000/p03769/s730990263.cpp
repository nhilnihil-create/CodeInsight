#include<bits/stdc++.h>
#define taskname "A"
#define pb push_back
#define mp make_pair
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
const int maxn = 2e5 +5;
const int inf = 1e9 + 1;
const ll llinf = 1e18 + 5;
ll n;
vector<int> Build(int x , ll n){
    vector<int> res(0);
    if(n == 1)return res;
    if(n & 1)res = Build(x + 1 , n - 1);
    else res = Build(x + 1 , n / 2);
    if(n & 1)res.insert(res.begin(),x);
    else res.pb(x);
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if(fopen(taskname".inp", "r")) {
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }
    ll n;cin >> n;
    vector<int> res = Build(1 , n + 1);
    cout << res.size() * 2 << endl;
    for(int c : res)cout << res.size() - c + 1 << " ";
    for(int i = 1 ; i <= (int)res.size() ; ++i)cout << i << " ";

}

