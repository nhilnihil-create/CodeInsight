#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    for(int i = 0; i < 4; i++){
        cout << s.at(i);
    }
    cout << ' ';
    for(int i = 4; i < 12; i++){
        cout << s.at(i);
    }
    cout << endl;
    return 0;
}