#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, ret =""; cin >>s;
    for (auto c: s) {
        if (c == 'B') {if(ret.size()>0)ret.pop_back();}
        else {ret.push_back(c);}
    }
    cout << ret << endl;
    return 0;
}