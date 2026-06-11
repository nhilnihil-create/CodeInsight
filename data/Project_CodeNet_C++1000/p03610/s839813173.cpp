#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++) {
        if(i%2) continue;
        else cout << s[i];
    }
    cout << endl;

    return 0;
}
