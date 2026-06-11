#include <bits/stdc++.h>
using namespace std;

vector<int> evens, odds;
int N, M;
int main(){ 
    cin >> N >> M;
    while (M --) {
        int x;
        cin >> x;
        if (x % 2) {
            odds.push_back(x);
        } else {
            evens.push_back(x);
        }
    }
    if (odds.size() > 2) {
        cout << "Impossible\n";
        return 0;
    }
    if (odds.size() == 0) {
        for (int x : evens) cout << x << ' ';
        cout << '\n';

        cout << 1 + evens.size() + (evens.back() > 2) << '\n';
        cout << 1 << ' ';
        for (int i = 0; i < (int) evens.size() - 1; i ++) {
            cout << evens[i] << ' ';
        }
        cout << 1 << ' ';
        if (evens.back() > 2) cout << evens.back() - 2 << ' ';
        cout << '\n';
        return 0;
    }
    if (odds.size() == 1) {
        cout << odds[0] << ' ';
        for (int x : evens) cout << x << ' ';
        cout << '\n';

        if (evens.empty()) {
            cout << 1 + (odds[0] > 1) << '\n';
            cout << 1 << ' ';
            if (odds[0] > 1) cout << odds[0] - 1 << ' ';
            cout << '\n';
            return 0;
        }
        cout << 1 + evens.size() + (evens.back() > 2) << '\n';
        cout << odds[0] + 1 << ' ';
        for (int i = 0; i < (int) evens.size() - 1; i ++) {
            cout << evens[i] << ' ';
        }
        cout << 1 << ' ';
        if (evens.back() > 2) cout << evens.back() - 2 << ' ';
        cout << '\n';
        return 0;
    }
    if (odds.size() == 2) {
        cout << odds[0] << ' ';
        for (int x : evens) cout << x << ' ';
        cout << odds[1] << '\n'; 

        cout << 1 + evens.size() + (odds[1] > 1) << '\n';
        cout << odds[0] + 1 << ' ';
        for (int i = 0; i < (int) evens.size(); i ++) {
            cout << evens[i] << ' ';
        }
        if (odds[1] > 1) cout << odds[1] - 1 << '\n';
        return 0;
    }
    return 0;
}
