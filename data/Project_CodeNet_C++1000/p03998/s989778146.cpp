#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    vector<string> str(3, "");
    for (int i = 0; i < 3; i++) {
        cin >> str[i]; reverse(str[i].begin(), str[i].end());
    }
    int now = 0, tmp = 0;
    while (true) {
        if (str[now].length() == 0) break;
        if (str[now][str[now].length() - 1] == 'a') {
            tmp = 0;
        };
        if (str[now][str[now].length() - 1] == 'b') {
            tmp = 1;
        };
        if (str[now][str[now].length() - 1] == 'c') {
            tmp = 2;
        };
        str[now].pop_back();
        now = tmp;
    }
    cout << (char)(now + 65) << endl;
}