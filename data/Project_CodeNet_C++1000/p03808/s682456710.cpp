#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();


int main() {
    ll n;
    cin >> n;
    vector<ll> arr(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll acc = accumulate(arr.begin(), arr.end(), 0LL);
    ll step_sum = (1+n) * n / 2;
    if (acc % step_sum != 0) {
        cout << "NO" << endl;
    } else {
        ll cnt = acc / step_sum;
        ll ans = 0;
        arr.push_back(arr[0]);
        for(int i = 1; i <= n; i++) {
            ll goal = arr[i-1] + cnt;
            if (arr[i] > goal) {
                cout << "NO" << endl;
                return 0;
            } else {
                if ((goal - arr[i]) % n != 0) {
                    cout << "NO" << endl;
                    return 0;
                } else {
                    ans += (goal - arr[i]) / n;
                }
            }
        }
        if (cnt == ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}


