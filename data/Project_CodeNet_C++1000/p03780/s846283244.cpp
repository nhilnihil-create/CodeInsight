#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

int N, K;
vector<long> a;
bitset<5005> dp;

// when a <= b and b is unnecessary, a is also unnecessary.
bool C(long i) {
    dp >>= 5005;
    dp[0] = true;

    for(int j = 0; j < N; ++j) {
        if(i == j) continue;
        for(int k = K; k >= a[j]; --k) {
            dp[k] = dp[k] | dp[k - a[j]];
        }
    }

    bool need = false;
    for(int k = K - a[i]; k < K; ++k) need |= dp[k];
    return need;
}

int main(){
    cin.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> K;
    long tmp;
    for(int i=0; i < N; ++i) {
        cin >> tmp;
        if(tmp < K) a.push_back(tmp);
    }
    sort(a.begin(), a.end());
    N = (int)a.size();

    // binary search
    int ng = -1, ok = N;
    while(abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if(C(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << '\n';
    return 0;
}