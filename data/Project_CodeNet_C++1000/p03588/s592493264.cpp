#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define mod 1000000007
 
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
 
int lcm(int a, int b) { return a * b / gcd(a, b); }

int main(){
    int n;
    cin >> n;
    vector<pair<ll, ll>> p(n);
    for (int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        p[i] = make_pair(a, b);
    }

    sort(p.begin(), p.end());

    ll ans = 0;
    ll upper = p[0].first - 1;
    ll mid = p[n - 1].first - p[0].first + 1;
    ll under = p[n - 1].second;
    ans = upper + mid + under;
    cout << ans << endl;
    return 0;
}