#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    string A, B;
    cin >> A >> B;

    if (A.size() < B.size()) cout << "LESS" << endl;
    else if(A.size() > B.size()) cout << "GREATER" << endl;
    else {
        if(A < B) cout << "LESS" << endl;
        else if(A == B) cout << "EQUAL" << endl;
        else cout << "GREATER" << endl;
    }
    
    return 0;
}