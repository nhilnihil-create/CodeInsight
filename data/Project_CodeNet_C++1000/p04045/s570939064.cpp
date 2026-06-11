#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main() {
    ll n, k;
    cin >> n >> k;
    vector<int> d(10, 0);
    for(int i = 0; i < k; i++) {
        int inp;
        cin >> inp;
        d[inp] = 1;
    }
    for(int i = n; i <= 100 * n; i++) {
        string s = to_string(i);
        int flag = 1;
        for(auto e : s) {
            if(d[e - '0']) {
                flag = 0;
                break;
            }
        }
        if(flag) {
            cout << i << endl;
            return 0;
        }
    }
}