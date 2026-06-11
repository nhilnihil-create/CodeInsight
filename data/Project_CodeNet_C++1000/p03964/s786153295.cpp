#include "bits/stdc++.h"

using namespace std;

long long minN(long long prev, long long next) {
    long long n = prev / next;
    if (prev % next != 0) {
        ++n;
    }
    return n;
}

void Main() {
    long long N;
    cin >> N;
    pair<long long, long long> ta;
    for (long long i = 0; i < N; ++i) {
        long long T, A;
        cin >> T >> A;
        if (i == 0) {
            ta = make_pair(T, A);
            continue;
        }

        long long n1 = minN(ta.first, T);
        long long n2 = minN(ta.second, A);
        long long n = max(n1, n2);
        ta.first = n * T;
        ta.second = n * A;
    }

    cout << (ta.first + ta.second) << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
