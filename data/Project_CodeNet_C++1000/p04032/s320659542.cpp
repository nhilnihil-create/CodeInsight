#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
const int INF=1e9+7;

int main() {
    string s;
    char rt;
    bool ok = 0;
    cin >> s;

    rep(i,27) {
        char t = 'a'+i;
        bool tok = 0;

        rep(j,s.size()-1)
            if(s.at(j)==t && s.at(j+1)==t) {
                tok=1;
                break;
            }
        if(!tok)
            rep(j,s.size()-2)
                if(s.at(j)==t && s.at(j+2)==t) {
                    tok=1;
                    break;
                }

        if(tok) {
            ok=1, rt=t;
            break;
        }
    }

    if(ok) {
        int t1=-1,t2=-1;
        rep(i,s.size()) {
            if(s.at(i)!=rt)
                continue;
            if(t1 == -1)
                t1 = i;
            else if(t2 == -1)
                t2 = i;
            if(t1!=-1 && t2!=-1) {
                if(t2-t1 < 3)
                    break;
                t1=t2, t2=-1;
            }
        }
        cout << t1+1 << " " << t2+1;
    } else
        cout << "-1 -1";
    cout << endl;
}