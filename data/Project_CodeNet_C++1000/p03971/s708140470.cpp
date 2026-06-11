#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int ok = 0, f = 1;
    rep(i, s.size()) {
        if(s[i]=='a'){
            if(a+b>ok){
                ok++;
                cout << "Yes" << endl;
            }
            else cout << "No" << endl;
        }
        else if(s[i]=='b'){
            if(a+b>ok && f <= b){
                f++;
                ok++;
                cout << "Yes" << endl;
            }
            else cout << "No" << endl;
        }
        else cout << "No" << endl;
    }
    return 0;
}