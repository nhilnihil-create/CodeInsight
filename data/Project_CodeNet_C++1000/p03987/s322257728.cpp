#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;
vector <int> a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for(auto &i : a) cin >> i;
    vector <int> g(n), h(n);
    vector <int> s;
    for(int i = 0 ; i < n ; i++){
        while(s.size() && a[i] < a[s.back()]) s.pop_back();
        if(s.size()) g[i] = s.back();
        else g[i] = -1;
        s.push_back(i);
    }
    s.clear();
    for(int i = n - 1 ; i >= 0 ; i--){
        while(s.size() && a[i] < a[s.back()]) s.pop_back();
        if(s.size()) h[i] = s.back();
        else h[i] = n;
        s.push_back(i);
    }
    ll ans = 0;
    for(int i = 0 ; i < n ; i++){
        ans += 1LL * a[i] * (i - g[i]) * (h[i] - i);
    }
    cout << ans << endl;
}
