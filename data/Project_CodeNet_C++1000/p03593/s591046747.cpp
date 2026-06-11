#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H,W; cin >> H >> W;
    vector<string> S(H);
    for (int i=0;i<H;++i) cin >> S[i];
    vector<int> cnt(26,0);
    for (int i=0;i<H;++i)
        for (int j=0;j<W;++j)
            ++cnt[S[i][j]-'a'];
    int odd0=((H&1)&&(W&1)),odd1=((H&1?W/2:0)+(W&1?H/2:0));
    for (int i=0;i<26;++i){
        if (cnt[i]&1) --odd0;
        if (cnt[i]%4==2) --odd1;
    }
    cout << (odd0==0&&0<=odd1?"Yes":"No") << '\n';
}