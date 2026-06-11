#include <bits/stdc++.h>
using namespace std;

int main() {
    string N, rev;
    cin >> N;
    rev = N;
    reverse(rev.begin(), rev.end());
    if (N==rev) cout << "Yes\n";
    else cout << "No\n";
}