#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    map<int, int> m;
    ll ans1=0, ans2=0;
    for (int i = 0; i < N; i++){
        ll a; cin >> a;
        m[a]++;
        if(m[a]==2){
            m[a] = 0;
            if(a>ans1) swap(a,ans1);
            if(ans1>ans2) swap(ans1, ans2);
        }
    }

    cout << ans1 * ans2 << endl;
}