#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main() {
    string s; cin >> s;
    int n = s.size();
    //sort(s.begin(), s.end());
    int g = 0;
    rep(i, n) if(s[i]=='g') g++;
    int p = n - g;
    int kachi = min(g, n/2);
    int make = n - n/2 - max(0, g-n/2);
    cout << kachi - make;
}
