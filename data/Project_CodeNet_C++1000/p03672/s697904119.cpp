#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;

    int len=0;
    string sbuff;
    for (int i=s.size()-2; i>1; i-=2) {
        sbuff=s.substr(0, i);

        bool ans=true;
        rep(i, sbuff.size()/2) {
            if (sbuff[i]!=sbuff[i+sbuff.size()/2]) {
                ans=false;
                break;
            }
        }
        if (ans==true) {
            len=sbuff.size();
            break;
        }
    }

    cout << len << endl;
    return 0;
}