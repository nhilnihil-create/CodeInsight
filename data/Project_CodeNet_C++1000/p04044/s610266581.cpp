#include <bits/stdc++.h>
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
    io();
    int n, l; cin >> n >> l;
    vector<string> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    string ans = "";
    for(int i = 0; i < n; ++i){
        ans += v[i];
    }
    return cout << ans << '\n', 0;
}