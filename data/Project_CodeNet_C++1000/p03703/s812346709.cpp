#include <bits/stdc++.h>
using namespace std;
#define ll long long


class BIT{
    public:
    int size;
    vector<int> tree;
    
    void set(int n){
        size = n;
        tree = vector<int>(n+1, 0);
        return;
    }
    
    void add(int a, int n) {
        int x = n;
        while (x <= size){
            tree[x] += a;
            x += (x & -x);
        }
        return;
    }
    
    int sum(int a) {
        int x = a;
        int sum = 0;
        while (x > 0) {
            sum += tree[x];
            x -= (x & -x);
        }
        return sum;
    }
    
};


int main(){
    int N, K;
    cin >> N >> K;
    
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    
    vector<ll> sum(N+1, 0);
    for (int i = 1; i <= N; i++) sum[i] = sum[i-1] + a[i-1] - K;
    vector<ll> t;
    t = sum;
    sort(t.begin(), t.end());
    auto result = unique(t.begin(), t.end());
    t.erase(result, t.end());
    for (int i = 0; i < N+1; i++) {
        sum[i] = distance(t.begin(), lower_bound(t.begin(), t.end(), sum[i]))+1;
    }
    
    BIT bit;
    bit.set(N+1);
    ll ans = 0;
    for (int i = 0; i < N+1; i++) {
        bit.add(1, sum[i]);
        ans += bit.sum(sum[i]) - 1;
    }
    cout << ans << endl;
}