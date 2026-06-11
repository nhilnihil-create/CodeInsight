#include <bits/stdc++.h>
using namespace std;

signed main(){
    int N, K; cin >> N >> K;
    vector<int> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    int g = a[0];
    for(int i = 1; i < N; i++) g = __gcd(g, a[i]);
    int num = *max_element(a.begin(), a.end());
    if(num >= K && K % g == 0) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
}
