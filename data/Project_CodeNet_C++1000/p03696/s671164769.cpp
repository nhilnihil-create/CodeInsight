#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    int level = 0;
    int fragment = 0;
    string s;
    string prefix = "";
    string suffix = "";

    cin >> N >> s;
    for(int i=0;i<N;i++) {
        if(s[i] == ')'){
            if(level == 0) {
                fragment++;
            } else {
                level--;
            }
        } else {
            level++;
        }
    }

    for(int i=0;i<fragment;i++) {
        prefix += '(';
    }
    for(int i=0;i<level;i++) {
        suffix += ')';
    }

    cout << prefix << s << suffix << "\n";

    return 0;
}
