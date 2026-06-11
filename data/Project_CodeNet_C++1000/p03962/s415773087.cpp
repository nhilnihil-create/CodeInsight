#include "bits/stdc++.h"

using namespace std;

void Main() {
    int a, b, c;
    cin >> a >> b >> c;

    set<int> p;
    p.insert(a);
    p.insert(b);
    p.insert(c);
    cout << p.size() << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
