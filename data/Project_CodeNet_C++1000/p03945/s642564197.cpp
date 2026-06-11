#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    string S; cin >> S;
    char prev = S[0];
    int step = 0;
    for (int i = 1; i < S.size(); i++) {
        if (S.at(i) != prev) step++;
        prev = S.at(i);
    }
    cout << step << endl;
}