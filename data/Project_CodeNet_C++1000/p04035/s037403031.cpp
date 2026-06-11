#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;

int main() {
    int N;
    long long L;
    cin >> N >> L;
    vector<long long> a(N);
    rep(i, N) cin >> a[i];
    
    long long sum = 0;
    rep(i, N) sum += a[i];
    int left = 0;
    int right = N;
    vector<int> ans;
    while (right - left > 1) {
        if (sum < L) {
            cout << "Impossible\n";
            return 0;
        }
        if (a[left] + a[left + 1] < L) {
            sum -= a[left];
            ans.push_back(left + 1);
            ++left;
        } else {
            sum -= a[right - 1];
            ans.push_back(right - 1);
            --right;
        }
    }
    cout << "Possible\n";
    rep(i, N - 1) cout << ans[i] << "\n";
    return 0;
}
