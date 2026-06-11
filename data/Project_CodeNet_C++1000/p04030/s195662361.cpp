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

    stack<char> stck;
    int len_ = s.size();
    for (int i=0; i<len_; i++) {
        char c = s[i];
        if (c == '0') {
            stck.push('0');
        } else if (c == '1') {
            stck.push('1');
        } else {
            if (!stck.empty()) {
                stck.pop();
            }
        }
    }

    vector<char>vec;
    while (!stck.empty()) {
        vec.emplace_back(stck.top());
        stck.pop();
    }

    reverse(vec.begin(), vec.end());
    for (int i=0; i<vec.size(); i++) {
        cout << vec[i];
    }

    cout << endl;
    return 0;
}