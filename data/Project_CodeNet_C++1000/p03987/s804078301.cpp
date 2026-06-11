#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    vector<int> b(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        b[a-1] = i;
    }
    set<int> ar;
    ar.insert(-1);
    ar.insert(N);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll t = b[i];
        auto it1 = ar.lower_bound(t);
        auto it2 = it1;
        it1--;
        ans += (ll)(t-(*it1)) * ((*it2)-t) * (i+1);
        ar.insert(t);
    }
    cout << ans << endl;
    return 0;
}