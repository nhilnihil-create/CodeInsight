#include<bits/stdc++.h>
using namespace std;

int main(void) {
    string a, b, c;
    cin >> a >> b >> c;
    if (*(a.end() - 1) == *b.begin() && *(b.end() - 1) == *c.begin()) cout << "YES";
    else cout << "NO";
}