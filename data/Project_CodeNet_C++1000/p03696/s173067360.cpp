#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 2e9;
//const ll INF = 9e18;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int mn = 0;
    int last = 0;
    int x = 0;
    for (int i=0;i<n;i++){
        if (s[i] == '(') x++; else x--;
        mn = min(mn,x);
        if (i==n-1) last = x;
    }
    if (0 == mn) {
        for (int i=last;i>0;i--) s += ")";
    } else if (mn == last){
        for (int i=0;i>last;i--) s = "(" + s;
    } else {
        for (int i=0;i>mn;i--) s = "(" + s;
        for (int i=last;i>mn;i--) s += ")";
    }
    cout << s << "\n";
}