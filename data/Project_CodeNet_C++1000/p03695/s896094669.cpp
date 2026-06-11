#include<bits/stdc++.h>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;

signed main() {
    int n;
    cin >> n;
    vector<bool> color(8, false);
    int over = 0;

    rep(i, n){
        int tmp;
        cin >> tmp;
        if(tmp < 400) color[0] = true;
        else if(tmp < 800) color[1] = true;
        else if(tmp < 1200) color[2] = true;
        else if(tmp < 1600) color[3] = true;
        else if(tmp < 2000) color[4] = true;
        else if(tmp < 2400) color[5] = true;
        else if(tmp < 2800) color[6] = true;
        else if(tmp < 3200) color[7] = true;
        else over++;
    }

    int cnt = 0;
    rep(i, 8) if(color[i]) cnt++;
    int ans_max = cnt;
    if(cnt != 0){
        while(over > 0){
            ans_max++;
            over--;
        }
    }else{
        cnt = 1;
        ans_max = over;
    }
    
    cout << cnt << " " << ans_max << endl;
    return 0;
}