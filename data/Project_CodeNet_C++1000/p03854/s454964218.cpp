#include "bits/stdc++.h"

using namespace std;

void Main() {
    string S;
    cin >> S;

    string dream = "dream";
    string dreamer = "dreamer";
    string erase = "erase";
    string eraser = "eraser";

    bool ans = true;
    while (!S.empty()) {
        int n = S.size();
        if (n < 5) {
            ans = false;
            break;
        }
        if (n >= 5 && S.substr(n - 5, 5) == dream) {
            S = S.substr(0, n - 5);
            continue;
        }
        else if (n >= 5 && S.substr(n - 5, 5) == erase) {
            S = S.substr(0, n - 5);
            continue;
        }
        else if (n >= 6 && S.substr(n - 6, 6) == eraser) {
            S = S.substr(0, n - 6);
            continue;
        }
        else if (n >= 7 && S.substr(n - 7, 7) == dreamer) {
            S = S.substr(0, n - 7);
            continue;
        }
        else {
            ans = false;
            break;
        }
    }
    cout << (ans ? "YES" : "NO") << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
