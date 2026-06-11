#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a.at(i);
    
    int pos = 0;
    int diff = 0;
    int count = 1;
    for (int i = 1; i < N; i++) {
        diff = a.at(i) - a.at(i - 1);
        if (pos == 0) {
            if (diff > 0) pos = 1;
            if (diff < 0) pos = -1;
        } else if (pos == 1) {
            if (diff < 0) {
                pos = 0;
                count++;
            }
        } else {
            if (diff > 0) {
                pos = 0;
                count++;
            }
        }
    }
    cout << count << endl;
}
