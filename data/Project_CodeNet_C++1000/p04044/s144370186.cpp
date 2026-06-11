#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, l;
    cin >> n >> l;
    vector<string> s(n);
    for (int i=0; i<n; i++) cin >> s[i];
    sort(s.begin(), s.end());
    for (auto x : s) cout << x;
    cout << endl;
    return 0;
}