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
    map<char, int>d;
    int s_size = S.size();
    for (int i=0; i<s_size; i++) {
        d[S[i]] += 1;
    }

    bool exist_S = false;
    bool exist_N = false;
    bool exist_W = false;
    bool exist_E = false;

    for (auto c: d) {
        if (c.first == 'E') {
            exist_E = true;
        } else if (c.first == 'W') {
            exist_W = true;
        } else if (c.first == 'N') {
            exist_N = true;
        } else if (c.first == 'S') {
            exist_S = true;
        }
    }

    if (exist_E && !exist_W) {
        cout << "No" << endl;
    } else if (exist_W && !exist_E) {
        cout << "No" << endl;
    } else if (exist_N && !exist_S) {
        cout << "No" << endl;
    } else if (exist_S && !exist_N) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}