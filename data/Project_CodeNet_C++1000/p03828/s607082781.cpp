#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <iterator>
#include <set>


using namespace std;

vector<pair<long, long>> prime_factorization(long n) {
    vector<pair<long, long>> res;

    for (long i = 2; i * i <= n; ++i) {
        if (n % i != 0) {
            continue;
        }

        long ex = 0;

        while (n % i == 0) {
            ex += 1;
            n = n / i;
        }

        res.emplace_back(i, ex);
    }

    if (n != 1) {
        res.emplace_back(n, 1);
    }

    return res;

}


int main() {

    long N;
    cin >> N;

    map<long, long> exp;

    for (long n = 1; n <= N; ++n) {
        vector<pair<long, long>> vs = prime_factorization(n);
        for (auto kv:vs) {
            exp[kv.first] += kv.second;
        }
    }
    long M = 1000000000 + 7;
    long result = 1;
    for (auto kv:exp) {
        result = (result * (kv.second + 1)) % M;
    }

    cout << result << endl;

    return 0;

}