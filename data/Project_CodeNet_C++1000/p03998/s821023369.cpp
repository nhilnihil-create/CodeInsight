#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

void erase(string &S, char &ans, char &next) {
    if (S.empty()) {
        ans = toupper(next);
    } else {
        next = S.at(0);
        S.erase(0, 1);
    }
}

int main() {
    string A, B, C;
    cin >> A >> B >> C;
    char ans;
    char next = 'a'; 
    rep(i,300) {
        if (next == 'a') erase(A, ans, next);
        else if (next == 'b') erase(B, ans, next);
        else if (next == 'c') erase(C, ans, next);
    }
    cout << ans << endl;
}
