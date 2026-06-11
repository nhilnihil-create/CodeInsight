#include <bits/stdc++.h>

using namespace std;


int main() {
    string w;
    cin >> w;
    vector<int> v(26,0);
    for(int i = 0; i < w.size(); i++) {
        v[w[i] - 'a']++;
    }
    bool ok = true;
    for(int i = 0; i < 26; i++) {
        if(v[i] % 2 != 0) {
            ok = false;
        }
    }
    if(ok) {
        puts("Yes");
    } else {
        puts("No");
    }
    return 0;
}