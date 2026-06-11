#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

int main() {
    int n, val;
    cin >> n;
    unordered_map<int, int> cnt;
    for(int i = 0; i < n; i++) {
        cin >> val;
        cnt[val] += 1;
    }
    int even_cnt = 0;
    for(auto p: cnt) {
        if (p.second % 2 == 0) {
            even_cnt += 1;
        }
    }
    if (even_cnt % 2 == 1) {
        cout << cnt.size() -1 << endl;
    } else {
        cout << cnt.size() << endl;
    }

    return 0;
}


