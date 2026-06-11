#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    string a = s.substr(0,4);
    string b = s.substr(4);
    cout << a << " " << b << "\n";
    return 0;
}