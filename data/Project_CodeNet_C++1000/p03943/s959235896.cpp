#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    if(a == b+c) cout << "Yes" << endl;
    else if(b== a+c) cout << "Yes" << endl;
    else if(c == b+a) cout << "Yes" << endl;
    else cout << "No" << endl;

}