#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int s[n];

    int i;
    for(i = 0; i < n; i++) {
        cin >> s[i];
    }

    int cnt = 0;
    for(i = 0; i < n; i++) {
        while(i+1 < n && s[i] == s[i+1]) {
            i++;
        }
        if (i+1 < n && s[i] < s[i+1]) {
            while(i+1 < n && s[i] <= s[i+1]) {
                i++;
            }
        }
        else if (i+1 < n && s[i] > s[i+1]) {
            while(i+1 < n && s[i] >= s[i+1]) {
                i++;
            }
        }
        cnt++;
    }
    cout << cnt << endl;
}
