#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    long long cnt = 0;
    string str;
    char tmpStr;
    cin >> str;

    tmpStr = str.at(0);
    for (int i = 1; i < str.size(); i++) {
        if (tmpStr == str.at(i)) continue;

        tmpStr = str.at(i);
        cnt++;
    }

    cout << cnt;
    //
}
