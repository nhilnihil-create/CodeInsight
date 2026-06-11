#include <bits/stdc++.h>
#define MAXN 2010
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
#define in_range(x, y, n) (x >= 0 and x<n and y >=0 and y<n)
using namespace std;
const ll mod = 1e9 + 7;

int main (){
    ios_base::sync_with_stdio(false);
    ll n, x, ans = 0;

    cin >> n >> x;

    vector<int> v(n);

    for (int i=0; i<n; i++){
        cin >> v[i];
    }
    for (int i=0; i<n-1; i++){
        if (v[i] + v[i+1] > x){
            int differ = v[i] + v[i+1] - x;
            ans += differ;
            if (differ > v[i+1]){
                differ -= v[i+1];
                v[i+1] = 0;
                v[i] -= differ;
            }
            else {
                v[i+1] -= differ;
            }
        }
    }

    cout << ans << endl;
    return 0;
}