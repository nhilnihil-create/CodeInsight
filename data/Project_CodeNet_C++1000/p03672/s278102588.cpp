#include<bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    reverse(S.begin(), S.end());
    int len = S.size()/2;
    for (int i=0; i<len; i++) {
        S.erase(0, 2);
        if (S.substr(0, S.size()/2)==S.substr(S.size()/2, S.size()/2)) {
            cout << S.size() << "\n";
            return 0;
        }
    }
    cout << "0\n";
}