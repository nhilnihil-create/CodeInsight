#include<bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    map<char, int> cnt;
    for(int i = 0; i < S.size(); i++) {
        if(cnt.count(S[i]) == 0) {
            cnt[S[i]] = 1;
        } else {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    return 0;
}