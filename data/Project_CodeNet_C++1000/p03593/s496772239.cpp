#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

int main(){
    int H, W; cin >> H >> W;
    string v[105];
    REP(i,H) cin >> v[i];
    int cnt[26];
    memset(cnt,0,sizeof(cnt));
    REP(i,H) REP(j,W) cnt[v[i][j]-'a']++;
    REP(i,26) cnt[i] %= 4;
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt4 = 0;
    REP(i,26) {
        if(cnt[i] == 0) cnt4++;
        else if(cnt[i] == 2) cnt2++;
        else cnt1++;
    }
    if(H%2 && W%2) {
        if(cnt1 == 1 && cnt2 <= (H+W-2)/2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else if(H%2 && !(W%2)) {
        if(cnt1 == 0 && cnt2 <= W/2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else if(!(H%2) && W%2) {
        if(cnt1 == 0 && cnt2 <= H/2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else {
        if(cnt1 == 0 && cnt2 == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}