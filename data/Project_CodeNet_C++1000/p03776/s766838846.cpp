#include "bits/stdc++.h"

using namespace std;

map<long long, long long> primeFactorize(long long n) {
    map<long long, long long> ret;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            ret.insert(make_pair(i, 0LL));
        }
        while (n % i == 0) {
            ret[i] += 1;
            n /= i;
        }
    }
    if (n > 1LL) {
        ret.insert(make_pair(n, 1LL));
    }
    return ret;
}

long long nCk(long long n, long long k) {
    map<long long, long long> pFac;
    for (long long i = n - k + 1; i <= n; ++i) {
        map<long long, long long> fac_i = primeFactorize(i);
        for (auto e : fac_i) {
            if (pFac.count(e.first) == 0) {
                pFac.insert(make_pair(e.first, 0LL));
            }
            pFac[e.first] += e.second;
        }
    }
    for (long long i = 2; i <= k; ++i) {
        map<long long, long long> fac_i = primeFactorize(i);
        for (auto e : fac_i) {
            pFac[e.first] -= e.second;
        }
    }
    long long ret = 1LL;
    for (auto e : pFac) {
        for (long long i = 0; i < e.second; ++i) {
            ret *= e.first;
        }
    }
    return ret;
}

void sameElements(long long N, long long A, long long B, long long v) {
    long long ret = 0LL;
    for (long long i = A; i <= B; ++i) {
        ret += nCk(N, i);
    }
    cout << (double)v << endl << ret << endl;
}

void Main() {
    long long N, A, B;
    cin >> N >> A >> B;
    vector<long long> v(N, 0LL);
    for (long long i = 0; i < N; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), greater<long long>());

    map<long long, long long> elements;
    long long minElement = v.front();
    long long numMinElements = 1LL;
    for (long long i = 0; i < A; ++i) {
        if (elements.count(v[i]) == 0) {
            elements.insert(make_pair(v[i], 0LL));
        }
        elements[v[i]] += 1;
        if (v[i] < minElement) {
            minElement = v[i];
            numMinElements = 1LL;
        }
        else {
            ++numMinElements;
        }
    }

    long long numMinElements_inV = 0LL;
    for (long long i = 0; i < N; ++i) {
        if (v[i] == minElement) {
            ++numMinElements_inV;
        }
    }
    if (minElement == v.front()) {
        sameElements(numMinElements_inV, A, min(B, numMinElements_inV), v.front());
        return;
    }


    double ans_avg = 0.0;
    for (auto e : elements) {
        ans_avg += e.first * e.second;
    }
    ans_avg /= (double)A;
    long long ans_nComb = nCk(numMinElements_inV, numMinElements);
    cout << ans_avg << endl << ans_nComb << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
