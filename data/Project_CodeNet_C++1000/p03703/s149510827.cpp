#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> P;

struct BIT{
    int N;
    vector<int> dat;
    BIT() {}
    BIT(int n) {
        N = n;
        dat.resize(N + 1);
    }
    void add(int k, int x){
        k++;
        while(k <= N){
            dat[k] += x;
            k += k&-k;
        }
    }
    int sum(int k){
        int s = 0;
        while(k > 0){
            s += dat[k];
            k -= k&-k;
        }
        return s;
    }
};

signed main(){
    int n, k;
    cin >> n >> k;
    vector<int> d(n);
    for(int i = 0; i < n; i++) cin >> d[i];
    vector<int> cs(n + 1);
    for(int i = 0; i < n; i++) cs[i + 1] = cs[i] + d[i] - k;
    vector<int> a = cs;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    for(int i = 0; i < n + 1; i++) cs[i] = lower_bound(a.begin(), a.end(), cs[i]) - a.begin();
    int ans = 0;
    BIT b(n + 1);
    for(int i = 0; i < n + 1; i++){
        ans += b.sum(cs[i] + 1);
        b.add(cs[i], 1);
    }
    cout << ans << endl;
}