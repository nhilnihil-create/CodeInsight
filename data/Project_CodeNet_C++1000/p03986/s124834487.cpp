#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    int cnt = 0;
    int ans = 0;
    int n = s.size();
    for(int i = 0; i < n; i++) {
        if (s[i] == 'S') {
            cnt++;
        } else {
            if (cnt > 0) {
                cnt--;
                ans+=2;
            }
        }
    }
    cout << n - ans << endl;
    return 0;
}
