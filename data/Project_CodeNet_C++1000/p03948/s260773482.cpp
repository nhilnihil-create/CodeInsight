#include <bits/stdc++.h>
using namespace std;
int main () {
    long long N, T;
    cin >> N >> T;
    vector<long long> A(N);
    long long m;
    long long p = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (i == 0) {
            m = A[i];
        }
        else {
            p = max(p, (A[i]-m)*(T/2));
            m = min(m, A[i]);
        }
    }
    p /= T/2;
    map<long long, vector<int>> mp;
    for (int i = 0; i < N; i++) {
        mp[A[i]].push_back(i);
    }
    map<long long, int> mm;
    for (int i = 0; i < N; i++) {
        if (mp.find(A[i]+p) != mp.end()) {
            auto j = mp[A[i]+p].end() - upper_bound(mp[A[i]+p].begin(), mp[A[i]+p].end(), i);
            mm[A[i]+p] += j;
            mm[A[i]] += 1;
        }
    }
    long long ans = 0;
    for (auto x: mm) {
        if (mm.find(x.first - p) == mm.end()) {
            vector<int> v;
            long long i = x.first;
            while (mm.find(i) != mm.end()) {
                v.push_back(mm[i]);
                i += p;
            }
            int a = 0, b = 0;
            for (int i = 0; i < v.size(); i += 2) {
                a += v[i];
            }
            for (int i = 1; i < v.size(); i += 2) {
                b += v[i];
            }
            ans += min(a, b);
        }
    }
    cout << ans << endl;
}