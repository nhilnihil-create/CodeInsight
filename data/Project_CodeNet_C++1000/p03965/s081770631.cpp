#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)

#define GU 0
#define PA 1

signed main()
{
    string s; cin >> s;
    int l = s.size();

    int myCard = GU;
    int ans = 0;
    rep(i,l){
        char c = s[i];
        if (c == 'g'){
            if (myCard == PA) ++ans;
        } else {
            if (myCard == GU) --ans;
        }
        if (myCard == GU) myCard = PA;
        else myCard = GU;
    }

    cout << ans << endl;

    return 0;
}
