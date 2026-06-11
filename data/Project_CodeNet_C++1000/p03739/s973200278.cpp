#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
const int oo = 1e9 + 7;
const int mod = 1e9 + 7, maxn = 100100;
const long double PI = acos(-1);
 
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll sum = 0, ans = 0, res = 0, signal;
    cin >> n;

    vector<int> v(n);

    for (auto& x: v) cin >> x;

    signal = 1;
    for (int i=0; i<n; i++){
        sum += v[i];
        // cout << sum << endl;
        if (signal * sum <= 0){
            // cout << v[i] << " " << signal << " " << sum << endl;
            ans += abs(sum) + 1;
            sum = signal;
        }
        signal*=-1;
    }

    signal = -1;
    sum = 0;
    for (int i=0; i<n; i++){
        sum += v[i];
        if (signal * sum <= 0){
            res += abs(sum) + 1;
            sum = signal;
        }
        signal*=-1;
    }

    cout << min(ans, res)<< endl;
    return 0;
}