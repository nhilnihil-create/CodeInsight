#include<iostream>
#include<vector>
using namespace std;
int main() {
    string s; cin >> s;
    for (int i = 1; i < s.size(); ++i)
    {
        int sz = s.size() - i;
        if (sz % 2 != 0)
            continue;
        if (s.substr(0, sz / 2) == s.substr(sz / 2, sz / 2)){
            cout << sz;
        break;
    }

    }
       
    return 0;
}