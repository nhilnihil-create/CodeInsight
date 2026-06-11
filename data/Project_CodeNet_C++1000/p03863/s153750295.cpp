#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    string s;
    cin >> s;
    int n=s.size();
    bool flag;
    if (s[0]!=s[n-1]) {
        if (n%2==1) flag=true;
        else flag=false;
    } else {
        if (n%2==1) flag=false;
        else flag=true;
    }
    if (flag) cout << "First" << endl;
    else cout << "Second" << endl;
}
