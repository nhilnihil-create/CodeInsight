#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, tmp;
    cin >> n;
    deque<int> a;
    int reverse = -1;
    rep(i,n) {
        cin >> tmp;
        if (reverse == -1) {
            a.push_back(tmp);
        } else {
            a.push_front(tmp);
        }
        reverse *= -1;
    }
    if (reverse == -1) {
        while (!a.empty()) {
            cout << a.front() << " ";
            a.pop_front();
        }
    } else {
        while (!a.empty()) {
            cout << a.back() << " ";
            a.pop_back();
        }
    }
}
