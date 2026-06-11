#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <cmath>

using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<char> v;
    for (char c: s) {
        v.push_back(c);
    }
    sort(v.begin(), v.end());
    char prev = v[0];
    int cnt = 1;
    for (int i=1; i<s.length(); i++) {
        if (prev == v[i]) {
            cnt++;
            prev = v[i];
        }
        else {
            if (cnt % 2 == 1) {
                cout << "No\n";
                return 0;
            }
            else {
                cnt = 1;
                prev = v[i];
            }
        }
    }
    if (cnt % 2 == 1) cout << "No\n";
    else cout << "Yes\n";
    
    return 0;
}