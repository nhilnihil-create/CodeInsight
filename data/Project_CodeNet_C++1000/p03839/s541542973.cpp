#include<bits/stdc++.h>

int main(){
    using namespace std;
    size_t N, K;
    cin >> N >> K;
    vector<size_t> p(N + 1), n(N + 1);
    for(size_t i = 1; i <= N; ++i){
        long a;
        cin >> a;
        (a > 0 ? p : n)[i] = abs(a);
    }
    partial_sum(p.begin(), p.end(), p.begin());
    partial_sum(n.begin(), n.end(), n.begin());
    size_t ans{numeric_limits<size_t>::max()};
    for(size_t i = K; i <= N; ++i)ans = min(ans, p[i] - p[i - K]);
    for(size_t i = K; i <= N; ++i)ans = min(ans, n[i] - n[i - K]);
    cout << p.back() - ans << endl;
    return 0;
}