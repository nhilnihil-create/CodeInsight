#include<iostream>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i-1]) ans++;
    }
    printf("%d\n", ans);
}