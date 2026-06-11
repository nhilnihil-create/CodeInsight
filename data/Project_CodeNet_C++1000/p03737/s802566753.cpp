#include<bits/stdc++.h>
using namespace std;

int main(void) {
    string a, b, c;
    cin >> a >> b >> c;
    int d = 'a' - 'A';
    cout << (char)(a.at(0) - d) << (char)(b.at(0) - d) << (char)(c.at(0) - d);
}