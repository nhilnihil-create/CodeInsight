#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    int a, b;
    cin >> a >> str >> b;
    if(str.at(0) == '+') {
        cout << a+b << endl;
    } else {
        cout << a-b << endl;
    }
}