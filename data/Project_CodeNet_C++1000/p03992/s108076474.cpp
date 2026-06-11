#include<iostream>
#include<string>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    for (int i = 0; i < S.length(); i++) {
        cout << S[i];
        if (i == 3) cout << ' ';
    }
    cout << endl;
    return 0;
}