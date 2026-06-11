#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int64_t> a(n), b(n);
    map<int, int> m;
    for(auto& e : a){
        cin >> e;
        m[e]++;
    }
    sort(begin(a), end(a));
    partial_sum(begin(a), end(a), begin(b));
    int ans = 1;
    for(int i = n - 1; i > 0; i -= m[a[i]]){
        if(b[i-1] * 2 >= a[i]){
            if(m[a[i]] > 1){
                ans += m[a[i]];
                continue;
            }
            ans++;
        }else{
            break;
        }
    }
    if(m.size() == 1) ans = n;
    cout << ans << endl;
    return 0;
}