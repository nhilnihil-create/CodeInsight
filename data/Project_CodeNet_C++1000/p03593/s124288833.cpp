#include <bits/stdc++.h>

using namespace std;

int h, w;

pair<int, int> compute(int r, int c) {
    return {min(h - r - 1, r), min(w - c - 1, c)};
}

int main() {
    cin >> h >> w;
    map<pair<int, int>, int> cnt;
    map<char, int> freq;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cnt[compute(i, j)]++;
            char c;
            cin >> c;
            freq[c]++;
        }
    }
    vector<int> vals;
    for (auto i : freq) {
        vals.push_back(i.second);
    }
    int b[5] = {};
    for (auto i : cnt) {
        b[i.second]++;
    }
    for (int i = 4; i >= 0; i--) {
        for (int j = 0; j < b[i]; j++) {
            bool f = false;
            for (auto &&x: vals) {
                if (x >= i) {
                    x -= i;
                    f = true;
                    break;
                }
            }
            if(!f){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;


}
