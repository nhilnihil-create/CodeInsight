#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    int cur = a[1], turn = 0;
    if(a[0] < a[1]) {
        turn = 1;
    }
    else if(a[0] > a[1]) {
        turn = -1;
    }
    for(int i = 2; i < n; i++) {
        int turn_;
        if(a[i] > cur) {
            turn_ = 1;
        }
        else if(a[i] == cur) {
            turn_ = 0;
        }
        else {
            turn_ = -1;
        }
        if(turn == 0) {
            turn = turn_;
            cur = a[i];
        }
        else if(turn_ == 0) {
            cur = a[i];
        }
        else if(turn == turn_) {
            cur = a[i];
        }
        else {
            ans++;
            cur = a[i];
            if(i != n-1) {
                if(a[i] < a[i+1]) {
                    turn = 1;
                }
                else if(a[i] == a[i+1]) {
                    turn = 0;
                }
                else {
                    turn = -1;
                }
            }
        }
    }
    cout << ans + 1 << "\n";
    return 0;
}