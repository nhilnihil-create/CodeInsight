#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(j, m) for (int j = 0; j < (int)(m); j++)
#define rep2(i, l, n) for (int i = l; i < (int)(n); i++)

bool guumojiretu(string A) {
    int flag = 0;
    rep(i,A.size()/2) {
        if (A[i] != A[i + A.size()/2]) {
            flag++;
        }
    }
    if (flag == 0) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    string S;
    cin >> S;
    while(true) {
        S.pop_back();
        S.pop_back();
        if (guumojiretu(S)) {
            cout << S.size() << endl;
            break;
        }
        
    }
}

