#include "bits/stdc++.h"

using namespace std;

void Main() {
    long long N;
    cin >> N;
    long long power = 1;
    for (long long i = 0; i < N; ++i) {
        power *= (i + 1);
        power %= 1000000007;
    }
    cout << power << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
