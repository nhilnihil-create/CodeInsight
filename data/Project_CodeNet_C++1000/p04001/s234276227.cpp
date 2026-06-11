#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string s;
    cin >> s;

    int length = s.length();
    ll sum = 0;
    for (int mask = 0; mask < (1 << length - 1); mask++) {
        string temp = s.substr(length - 1, 1);
        for (int i = 0; i < length - 1; i++)  {
            if (1 & (mask >> i)) {
                sum += stol(temp);
                temp = s.substr(length - (i + 2), 1);
            } else {
                temp = s.substr(length - (i + 2), 1) + temp;
            }
        }
        sum += stol(temp);
    }

    cout << sum << endl;

    return 0;
}