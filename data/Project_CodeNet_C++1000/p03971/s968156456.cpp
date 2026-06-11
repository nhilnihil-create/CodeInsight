#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, total = 0, over = 0, a, b;
    string s;
    cin >> n >> a >> b;
    cin >> s;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'a') {
            if(total < a+b) {
                cout << "Yes\n";
                total++;
            } else {
                cout << "No\n";
            }
        } else if(s[i] == 'b') {
            if(total < a+b && over < b) {
                cout << "Yes\n";
                over++;
                total++;
            } else {
                cout << "No\n";
            }
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
