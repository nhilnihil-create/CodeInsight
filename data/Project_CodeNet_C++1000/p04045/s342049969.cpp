#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N, K;
    cin >> N >> K;
    set<string> usable;
    for (int i = 0; i <= 9; ++i) {
        usable.insert(to_string(i));
    }
    for (int i = 0; i < K; ++i) {
        string d;
        cin >> d;
        if (usable.count(d) > 0) {
            usable.erase(d);
        }
    }

    int ans = 0;
    while (true) {
        string N_str = to_string(N);
        bool pay = true;
        for (int i = 0; i < N_str.size(); ++i) {
            if (usable.count(N_str.substr(i, 1)) == 0) {
                pay = false;
                break;
            }
        }
        if (pay) {
            ans = N;
            break;
        }
        ++N;
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
