#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string S, answer = "CODEFESTIVAL2016";
    int count = 0;
    cin >> S;
    list<char> lst;
    for (int i = 0; i < S.size(); ++i) {
        if (S[i] != answer[i]) ++count;
    }
    cout << count << endl;
    return 0;
}