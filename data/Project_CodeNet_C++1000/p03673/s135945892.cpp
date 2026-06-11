#include "bits/stdc++.h"

using namespace std;

void Main() {
    int n;
    cin >> n;
    list<int> ans;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (n % 2 == 0) {
            if (i % 2 == 0) {
                ans.push_back(a);
            }
            else {
                ans.push_front(a);
            }
        }
        else {
            if (i % 2 == 0) {
                ans.push_front(a);
            }
            else {
                ans.push_back(a);
            }
        }
    }
    bool first = true;
    for (auto e : ans) {
        if (first) {
            cout << e;
            first = false;
        }
        else {
            cout << " " << e;
        }
    }
    cout << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
