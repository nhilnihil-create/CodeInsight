#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define se second
#define fi first
#define mp make_pair
#define pb push_back

const int mod = (int)1e9 + 7;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;
const int N = (int)1e5 + 100;
const int MAXA = (int)3e6;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    // ifstream cin("input.txt");
    //ofstream cout("output.txt");
    // freopen("nochange.in", "r", stdin);
    //freopen("nochange.out", "w", stdout);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 0,p = 0;
    for(int i = 0;i < n;i++){
        ll cur = p + 1;
        if(cur < a[i]){
            ans += a[i] / cur - (a[i] % cur == 0);
            a[i] = 1;
        }
        p = max(p, a[i]);
    }
    cout << ans;
    return 0;
}
