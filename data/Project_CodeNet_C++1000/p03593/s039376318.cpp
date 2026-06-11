#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; i++)

int main(){
    int H, W; cin >> H >> W;
    vector<string> A(H);
    unordered_map<char, int> mp;
    rep(i, 0, H) cin >> A[i];
    rep(i, 0, H) rep(j, 0, W) mp[A[i][j]]++;
    bool flag = true;

    if(H % 2 == 0 && W % 2 == 0){
        for(auto e: mp){
            if(e.second % 4 != 0){
                flag = false;
                break;
            }
        }
    }
    else if(H % 2 == 1 && W % 2 == 1){
        int S = 0, D = 0, Q = 0;
        for(auto e: mp){
            if(e.second % 4 == 0){
            }else if(e.second % 4 == 1){
                S += 1;
            }else if(e.second % 4 == 2){
                D += 1;
            }else{
                S++;
                D++;
            }
        }
        if(S > 1 || (H / 2 + W / 2) < D){
            flag = false;
        }
    }else if(H % 2 == 0 && W % 2 == 1){
        int S = 0, D = 0, Q = 0;
        for(auto e: mp){
            if(e.second % 4 == 0){
            }else if(e.second % 4 == 1){
                S += 1;
            }else if(e.second % 4 == 2){
                D += 1;
            }else{
                S++;
                D++;
            }
        }
        if(S > 0 || H / 2 < D){
            flag = false;
        }
    }else{
        int S = 0, D = 0, Q = 0;
        for(auto e: mp){
            if(e.second % 4 == 0){
            }else if(e.second % 4 == 1){
                S += 1;
            }else if(e.second % 4 == 2){
                D += 1;
            }else{
                S++;
                D++;
            }
        }
        if(S > 0 || W / 2 < D){
            flag = false;
        }
    }
    if(flag) puts("Yes");
    else puts("No");


}