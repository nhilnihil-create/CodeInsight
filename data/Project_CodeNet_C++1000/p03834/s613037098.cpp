#include<bits/stdc++.h>
using namespace std;

int main(void) {
    string s;
    getline(cin, s);
    replace(s.begin(), s.end(), ',', ' ');
    cout << s;
}