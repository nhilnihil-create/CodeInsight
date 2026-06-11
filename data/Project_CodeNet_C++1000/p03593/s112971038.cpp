#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt[26];
signed main() {
    int H,W;
    cin >> H >> W;
    vector<vector<char>>a(H,vector<char>(W));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> a[i][j];
            cnt[a[i][j]-'a']++;
        }
    }
    int B = 0,C = 0;
    if(H%2 == 1 && W%2 == 1) {
        C++;
        B = (H+W-1)/2;
    }
    else if(H%2 == 1 && W%2 == 0) {
        B = W/2;
    }
    else if(H%2 == 0 && W%2 == 1) {
        B = H/2;
    }
    for(int i = 0; i < 26; i++) {
        if(cnt[i]%2 == 1) {
            if(C) {
                cnt[i]--;
                C--;
            }
        }
        if(cnt[i]%4 == 2) {
            if(B) {
                cnt[i]-=2;
                B--;
            }
        }
        cnt[i]%=4;
    }
    for(int i = 0; i < 26; i++) {
        if(cnt[i] != 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}