#include<bits/stdc++.h>
using namespace std;

int main(void) {
    string s;
    cin >> s;
    cout << ((s.size()&1)^(s[0] == s[s.size()-1]) ? "First" : "Second") << endl;
}
