#include "bits/stdc++.h"

using namespace std;

void Main() {
    string s;
    cin >> s;

    string top = s.substr(0, 1);
    string last = s.substr(s.size() - 1, 1);
    cout << top << (s.size() - 2) << last << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
