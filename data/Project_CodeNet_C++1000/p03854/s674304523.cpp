#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define arep(x,n) for (int x: n)
using namespace std;

int main()
{
    string s; cin >> s;
    reverse(s.begin(), s.end());

    vector<string> t(4);
    t.at(0) = "dream"; 
    t.at(1) = "erase"; 
    t.at(2) = "eraser"; 
    t.at(3) = "dreamer"; 
    rep(i,4) {
        reverse(t.at(i).begin(), t.at(i).end());
    }

    bool can;

    for(int i = 0; i < s.size();) {
        can = false;
        for(int j = 0; j < 4; j++) {
            if(s.substr(i,t.at(j).size()) == t.at(j)) {
                can = true;
                i += t.at(j).size();
            }
        }
        if(!can) break;
    }

    if(can) cout << "YES" << endl;
    else cout << "NO" << endl;
}