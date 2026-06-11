#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;

    long spos=s.find("A");
    long lpos=s.rfind("Z");

    cout << lpos-spos+1 << endl;

    return 0;
}