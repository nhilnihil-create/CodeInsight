#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    string S;
    cin >> S;

    int64_t s_ = S.size();
    while (true) {
        S.erase(s_-1);
        s_ = S.size();
        bool is_guumozi = true;
        if (s_ % 2 != 0) {
            continue;
        }

        for (int i=0; i<s_/2; i++) {
            if (S[i] != S[s_/2+i]) {
                is_guumozi = false;
                break;
            }
        }

        if (is_guumozi) {
            break;
        }
    }

    cout << S.size() << endl;
    return 0;
}