#include <bits/stdc++.h>
using namespace std;
void print() {
    cout << endl;
}
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail) {
    cout << head;
    if (sizeof...(tail) != 0)
        cout << " ";
    print(forward<Tail>(tail)...);
}
template <class T>
void print(vector<T> &vec) {
    for (auto &a : vec) {
        cout << a;
        if (&a != &vec.back())
            cout << " ";
    }
    cout << endl;
}
template <class T>
void print(vector<vector<T>> &df) {
    for (auto &vec : df) {
        print(vec);
    }
}
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
using ll = long long;
const int INF = 1001001001;

int main() {
    int K, S;
    cin >> K >> S;
    int cnt = 0;
    rep(x, K+1) {
        rep(y, K+1) {
            int z = S-(x+y);
            if(0<=z && z<=K) cnt++;
        }
    }  
    print(cnt);
    return 0;
}