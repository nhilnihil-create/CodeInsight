#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

map<int, LL> dict, dict_q;

LL get_best(int t) {
    LL res = 0;
    for (map<int,LL>::iterator iter = dict.begin(); iter != dict.end(); iter++) {
        int A = iter->first;
        LL B = iter->second;
        if ((A | t) == t) res += B;
    }
    return res;
}

int main() {
    int N, K, A; LL B;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A >> B;
        if (dict.find(A) == dict.end()) {
            dict[A] = B;
        }
        else {
            dict[A] += B;
        }
    }
    int current = 0;
    LL res = get_best(K);
    for (int i = 30; i > 0; i--) {
        if (K & (1 << i)) {
            res = max(res, get_best(current + (1 << i) - 1));
            current = current + (1 << i);
        }
    }
    cout << res << endl;
    return 0;
}