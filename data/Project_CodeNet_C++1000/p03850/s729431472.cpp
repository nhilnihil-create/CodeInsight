#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5 + 5;

ll prefix[MAX];
ll abs_prefix[MAX];
ll sum(int l, int r){
    if(l > r) return 0;
    return prefix[r] - (l == 0 ? 0 : prefix[l - 1]);
}
ll abs_sum(int l, int r){
    if(l > r) return 0;
    return abs_prefix[r] - (l == 0 ? 0 : abs_prefix[l - 1]);
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    cin >> a[0];
    for(int i = 0; i < n - 1; i++){
        char sgn; int val; cin >> sgn >> val;
        if(sgn == '-') a[i + 1] = -val;
        else a[i + 1] = val;
    }
    ll res = 0;
    bool neg = false;
    for(int i = 0; i < n; i++){
        if(a[i] < 0) neg = true;
        if(i) prefix[i] = prefix[i - 1] + a[i];
        else prefix[i] = a[i];
        if(i) abs_prefix[i] = abs_prefix[i - 1] + abs(a[i]);
        else prefix[i] = abs(a[i]);
    }
    if(!neg){
        cout << sum(0, n - 1) << '\n';
        return 0;
    }
    int it1 = 0;
    int it2 = 0;
    ll ans = 0;
    while(a[it1] > 0) it1++;
    it2 = it1 + 1;
    while(it1 != n){
        while(a[it2] > 0) it2++;
        ll val = sum(0, it1) - abs_sum(it1 + 1, it2 - 1) + abs_sum(it2, n - 1);
        ans = max(ans, val);
        it1 = it2;
        it2 = it1 + 1;
    }
    cout << ans << '\n';
    return 0;
}
