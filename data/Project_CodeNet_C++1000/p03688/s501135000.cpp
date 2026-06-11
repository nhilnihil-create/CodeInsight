#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();


int main() {
    int n, val;
    cin >> n;
    vector<int> arr(n, 0);
    map<int, int> cnt;
    for(int i = 0; i < n; i++) {
        cin >> val;
        cnt[val] += 1;
    }
    if (cnt.size() > 2 || cnt.rbegin()->first-cnt.begin()->first > 1) {
        cout << "No" << endl;
        return 0;
    }
    if (cnt.rbegin()->first >= n) {
        cout << "No" << endl;
        return 0;
    }
    if (cnt.size() == 2) {
        int sm = cnt.begin()->first;
        int big = cnt.rbegin()->first;
        int unique_color = cnt[sm];
        int common_color = big-unique_color;
        if (common_color > 0 && common_color * 2 <= n-unique_color) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else if (cnt.size() == 1) {
        int freq = cnt.begin()->first;
        if (freq == n-1 || freq*2 <= n)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}

