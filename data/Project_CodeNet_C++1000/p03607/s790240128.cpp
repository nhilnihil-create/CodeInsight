#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N;
    cin >> N;
    set<int> A;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (A.count(a) > 0) {
            A.erase(a);
        }
        else {
            A.insert(a);
        }
    }
    cout << A.size() << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
