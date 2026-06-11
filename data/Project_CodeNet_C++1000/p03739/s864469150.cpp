#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll now = (a[0]==0) ? 1LL : a[0];
    ll tmp_ans1 = (a[0]==0) ? abs(a[0])+1LL : 0;
    for (int i = 1; i < n; ++i) {
        if (now >= 0 && now+a[i] >= 0) {
            tmp_ans1 += abs(now+a[i])+1LL;
            now = -1LL;
        }
        else if (now < 0 && now+a[i] <= 0) {
            tmp_ans1 += abs(now+a[i])+1LL;
            now = 1LL;
        }
        else {
            now += a[i];
        }
        //cout << "1: " << " " << i << " " << now << " " << tmp_ans1 << endl;
    }
    now = (a[0] < 0) ? 1LL : -1LL;
    ll tmp_ans2 = abs(a[0]) + 1LL;
    for (int i = 1; i < n; ++i) {
        if (now >= 0 && now+a[i] >= 0) {
            tmp_ans2 += abs(now+a[i])+1LL;
            now = -1LL;
        }
        else if (now < 0 && now+a[i] <= 0) {
            tmp_ans2 += abs(now+a[i])+1LL;
            now = 1LL;
        }
        else {
            now += a[i];
        }
        //cout << "2: " << i << " " << now << " " << tmp_ans2 << endl;
    }
    //cout << tmp_ans1 << " " << tmp_ans2 << endl;
    cout << min(tmp_ans1, tmp_ans2) << endl;
    return 0;
}
