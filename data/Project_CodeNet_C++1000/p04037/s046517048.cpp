#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pll = pair<long long,long long>;

bool isodd(const pll &p) { return (p.first + p.second) & 1; }
bool solve(vector<long long> &a) {
    int N = (int)a.size();
    sort(a.begin(), a.end(), greater<long long>());

    long long x = 0, y = a[0];
    vector<pll> ps;
    for (int i = 0; i < N; ++i) {
        if (a[i] != y) ps.push_back(pll(i-1, y)), y = a[i];
    }
    ps.push_back(pll(N-1, a[N-1]));
    if (ps.size() == 1) return isodd(ps[0]);
    for (auto p : ps) if (p.first == p.second) return false;
    
    for (int i = 0; i + 1 < ps.size(); ++i) {
        if (ps[i].first < ps[i].second && ps[i+1].first > ps[i+1].second) {
            if (ps[i].first < ps[i+1].second) return isodd(ps[i+1]);
            else if (ps[i].first > ps[i+1].second) return isodd(ps[i]);
            else return isodd(ps[i]) || isodd(ps[i+1]);
        }
    }
    if (ps[0].first > ps[0].second) return isodd(ps[0]);
    else return isodd(ps.back());
}

int main() {
    int N;
    while (cin >> N) {
        vector<long long> a(N);
        for (int i = 0; i < N; ++i) cin >> a[i], --a[i];

        if (solve(a)) cout << "First" << endl;
        else cout << "Second" << endl;
    }
}   
