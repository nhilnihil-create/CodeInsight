#include <bits/stdc++.h>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        int ind = i + 1;
        if (ind % 2 != 0) {
            cout << s[i];
        }
    }
    cout << endl;
    return 0;
}