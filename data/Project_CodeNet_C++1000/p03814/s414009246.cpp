#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    string s;
    cin >> s;
    int s_size = s.size();
    int a_index = INT_MAX;
    int z_index = INT_MIN;
    for (int i=0; i<s_size; i++) {
        if (s[i] == 'A' && i < a_index) {
            a_index = i;
        } else if (s[i] == 'Z' && i > z_index) {
            z_index = i;
        }
    }

    cout << z_index - a_index + 1 << endl;
    return 0;
}