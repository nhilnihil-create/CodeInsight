#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

int main(){
    string s;
    cin >> s;

    int cnt = 0;
    rep(i, s.size()) if(s[i] == 'p') cnt++;
    cout << (int(s.size()/2) - cnt) << endl;
    return 0;
}
