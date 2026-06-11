#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int N;
    cin >> N;
    string s, t;
    cin >> s >> t;
    int len = N * 2;
    for (int i=0; i<N; i++) {
        string n = s.substr(i);
        string m = t.substr(0, N-i);
        if (n == m) {
            len = N + i;
            break;
        }
    }

    cout << len << endl;
    return 0;
}