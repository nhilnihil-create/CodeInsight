#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    cout << S[0] + to_string(S.size()-2) + S[S.size()-1] << endl;
}
