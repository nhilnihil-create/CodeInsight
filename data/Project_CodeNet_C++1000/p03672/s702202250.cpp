#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    for (int i = 1; i * 2 < N; ++i) {
        S.erase(S.size() - 2);
        string front = S.substr(0, S.size()/2);
        string rear = S.substr(S.size()/2);
        if (front == rear) {
            cout << S.size() << endl;
            return 0;
        }
    }
}

