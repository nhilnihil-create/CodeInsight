#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();

int main() {
    ll n, L;
    cin >> n >> L;
    vector<ll> arr(n, 0);
    for(auto& val: arr)
        cin >> val;
    ll dis = 0, init_idx = 0;
    for(int i = 1; i < n; i++) {
        if (arr[i]+arr[i-1] >= L) {
            init_idx = i;
        }
    }
    // cout << "init_idx " << init_idx << endl;
    if (init_idx == 0) {
        cout << "Impossible" << endl;
    } else {
        vector<ll> ans;
        cout << "Possible" << endl;
        for(int i = init_idx; i < n; i++)
            ans.push_back(i);
        for(int i = init_idx-1; i > 0; i--)
            ans.push_back(i);
        reverse(ans.begin(), ans.end());
        for(int val: ans)
            cout << val<< endl;
    }
    return 0;
}


