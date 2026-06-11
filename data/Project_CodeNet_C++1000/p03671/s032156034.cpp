#include "bits/stdc++.h"

using namespace std;

void Main() {
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> bells;
    bells.push_back(a);
    bells.push_back(b);
    bells.push_back(c);
    sort(bells.begin(), bells.end());
    cout << bells[0] + bells[1] << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
