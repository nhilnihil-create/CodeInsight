#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define se second
#define fi first
#define mp make_pair
#define pb push_back
#define ll long long
const int MAXN = (int)1e7 + 1000;
const int N = (int)1e5 + 100;
const int mod = (int)1e9 + 7;
const int INF = (int)1e9;
ll a[N],b[N];
int main(){
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> a[i] >> b[i];
    ll ans = 0;
    for(int i = n;i >= 1;--i){
        ans += ((b[i] - (a[i] + ans) % b[i]) % b[i]);
    }
    cout << ans;
    return 0;
}
