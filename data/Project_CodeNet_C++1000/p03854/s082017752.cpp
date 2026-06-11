#include <bits/stdc++.h>
using namespace std;

string divide[4] = {"dream", "dreamer", "erase", "eraser"};

int main() {
    string S;
    cin >> S;

    queue<int> BFS_border;
    BFS_border.push(0);
    while (!BFS_border.empty()) {
        int target = BFS_border.front();
        BFS_border.pop();
        if (target == S.size()) {
            cout << "YES" << endl;
            return 0;
        }

        for (string s : divide) {
            if (S.substr(target, s.size()) == s) {
                BFS_border.push(target + s.size());
            }
        }
    }

    cout << "NO" << endl;
}