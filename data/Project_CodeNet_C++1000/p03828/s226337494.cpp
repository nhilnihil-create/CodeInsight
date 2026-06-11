#include <iostream>
#include <vector>
using namespace std;

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0;
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        res.push_back({a, ex});
    }
    if (N != 1) res.push_back({N, 1});
    return res;
}

int main() {
    long long N;
    cin >> N;
    long long res = 1;
    vector<int> a(N, 1);

    for (int i = 2; i<= N; i++) {
        const auto &pf = prime_factorize(i);
        //for (auto p : pf) res *= p.second + 1;
        for (auto p : pf) a[p.first-1] += p.second;
    }
    for (int i = 1; i<N; i++)  {
        res *= a[i];
        res %= 1000000007;
    }
    cout << res << endl;
}

