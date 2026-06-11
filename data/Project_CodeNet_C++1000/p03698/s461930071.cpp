#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <string.h>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    for (int i=0; i<s.length(); i++) {
        char c = s[i];
        for (int j=i+1; j<s.length(); j++) {
            if (c == s[j]) {
                cout << "no" << '\n';
                return 0;
            }
        }
    }
    cout << "yes" << '\n';
    return 0;
}