#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int H, W;
    cin >> H >> W;
    vector<int> count(26);
    for (int h=0;h<H;h++){
        for (int w=0;w<W;w++){
            char a;
            cin >> a;
            count[a-'a']++;
        }
    }
    int four = (H/2)*(W/2);
    while (four >0){
        bool ok = false;
        for (int i=0;i<26;i++){
            if (count[i] >= 4) {
                four--;
                count[i]-=4;
                ok = true;
            }
        }
        if (!ok) {
            cout << "No" << "\n";
            return 0;
        }
    }
    int two = (H/2)*(W - (W/2)*2) + (W/2)*(H - (H/2)*2);
    while (two > 0){
        bool ok = false;
        for (int i=0;i<26;i++){
            if (count[i] >= 2) {
                two--;
                count[i]-=2;
                ok = true;
            }
        }
        if (!ok) {
            cout << "No" << "\n";
            return 0;
        }
    }
    int one = (H - (H/2)*2)*(W - (W/2)*2);
    while (one > 0){
        bool ok = false;
        for (int i=0;i<26;i++){
            if (count[i] >= 1) {
                one--;
                count[i]-=1;
                ok = true;
            }
        }
        if (!ok) {
            cout << "No" << "\n";
            return 0;
        }
    }
    bool yes = true;
    for (int i=0;i<26;i++){
        if (count[i] != 0) yes = false;
    }
    if (yes) cout << "Yes" << "\n";
    else cout << "No" << "\n";
}