#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <queue>
#include <limits>
#include <map>
#include <cassert>
#include <iterator>
using namespace std;
using VI = vector<long>;

long cnt[101010];
long sum = 0;

struct item {
    long a, i, is_target;
};

int main() {
    int n;
    cin >> n;
    vector<item> as;
    for (int i = 0; i < n; i++) {
        long a;
        cin >> a;
        sum += a;
        as.push_back({a, i + 1, 0});
    }
    sort(as.begin(), as.end(), [](auto a, auto b) { return a.a == b.a ? a.i < b.i : a.a > b.a; });
    long target_ind = as.front().i;
    as.front().is_target = 1;
    for (int i = 1; i < n; i++) {
        if (as[i].i < target_ind) {
            target_ind = as[i].i;
            as[i].is_target = 1;
        }
    }

    long used = 0;
    target_ind = as.front().i;
    int prev_i = 0;
    for (int i = 1; i < n; i++) {
        if (as[i].is_target) {
            long tmp = 0;
            tmp += (as.front().a - as[i].a) * prev_i;
            for (int j = prev_i; j < i; j++) {
                tmp += as[j].a - as[i].a;
                as.front().a = as[i].a;
            }
            prev_i = i;
            cnt[target_ind] = tmp;
            target_ind = as[i].i;
            used += tmp;
        }
    }
    
    cnt[target_ind] = sum - used;
    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << endl;
    }
}
