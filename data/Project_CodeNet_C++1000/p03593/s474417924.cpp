#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int H, W;
    cin >> H >> W;
    map<int, int> count;
    rep(i, H){
        rep(j, W){
            char a;
            cin >> a;
            count[a-'a']++;
        }
    }
    map<int, int> count2;
    rep(i, 26) count2[count[i]]++;
    if(H % 2 == 1 && W % 2 == 1){
        // ともに奇数 4,2,2,1
        bool judge = true;
        int one = 0;
        int four = 0;
        int tmp = ((W/2) * (H/2));
        rep(i,26) if(count[i] % 2) one++;
        if(one > 1) judge = false;
        if(tmp > 0){
            rep(i,26) if(count[i] >= 4) four += count[i] / 4;
            if(((W/2) * (H/2)) > four) judge = false;
        }
        if(judge) cout << "Yes" << endl;
        else cout << "No" << endl;
    }else if(W % 2 == 0 && H % 2 == 0){
        // ともに偶数
        bool judge = true;
        rep(i, 26) if(count[i] % 4 > 0) judge = false;
        int cnt = 0;
        rep(i, 26) cnt += count[i] / 4;
        if(cnt*4 != H*W) judge = false;
        if(judge) cout << "Yes" << endl;
        else cout << "No" << endl;
    }else{
        // どっちか偶数でどっちか奇数
        bool judge = true;
        int four = 0;
        int two = 0;
        int tmp = ((W/2) * (H/2));
        rep(i, 26) if(count[i]%2) judge = false;
        if(tmp > 0){
            rep(i,26) four += count[i] / 4;
            if(((W/2) * (H/2)) > four) judge = false;
        }
        if(judge) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
