#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef unsigned long long ull;

struct key {
    ull sum;
    ull count;
    ull index;
};

bool operator<(const key& l, const key& r) {
    return l.sum < r.sum || (l.sum == r.sum && l.count < r.count) || (l.sum == r.sum && l.count == r.count && l.index < r.index);
}

ull N, A, tmp;
vector<ull> x;
map<key, ull> cache;

ull solve(ull sum, ull count, ull index) {
    if (index == N) {
        if (count == 0) {
            return 0;
        } else if (count * A == sum) {
            return 1;
        } else {
            return 0;
        }
    }

    if (sum > N * A) {
        return 0;
    }

    key tmpkey;
    tmpkey.sum = sum;
    tmpkey.count = count;
    tmpkey.index = index;

    if (cache.find(tmpkey) == cache.end()) {
        cache[tmpkey] = solve(sum, count, index + 1) + solve(sum + x[index], count + 1, index + 1);
    }

    return cache[tmpkey];
}

int main(void) {
    cin >> N >> A;

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        x.push_back(tmp);
    }

    cout << solve(0, 0, 0) << endl;

    return 0;
}
