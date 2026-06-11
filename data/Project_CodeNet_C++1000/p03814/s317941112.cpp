#include "bits/stdc++.h"

using namespace std;

void Main() {
    string s;
    cin >> s;
    int f = s.find_first_of('A');
    int l = s.find_last_of('Z');
    cout << (l - f + 1) << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
