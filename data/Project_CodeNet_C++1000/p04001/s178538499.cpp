#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


ll dfs(string s) {
    stringstream ss(s);
    ll x = 0;
    ss >> x;
    if (s.length() == 1) return x;
    for (int i = 1; i < s.length(); i++) {
        string left = s.substr(0, i);
        string right = s.substr(i);

        stringstream ss2(left);
        ll leftNum = 0;
        ss2 >> leftNum;

        int rightNum = dfs(right);
        x += leftNum * pow(2, right.length()-1) + rightNum; 
    }
    return x;
}


void solve() {
    string s; cin >> s;
    cout << dfs(s) << endl;    
}


int main() {
    solve();
    return 0;
}