#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;
int mod = 1000000007;

void solve();

int main(void){
    int H, W; cin >> H >> W;
    if(H % 2 == 1 && W % 2 == 0) swap(H, W);
    int alp[26] = {};
    bool ok = true;
    rep(i, H) rep(j, W){char temp; cin >> temp; alp[temp - 'a']++;}
    if(H % 2 == 1){
        //H, W両方奇数
        bool find_odd = false;
        rep(i, 26){
            if(find_odd && alp[i] % 2 == 1) ok = false;
            else if(alp[i] % 2 == 1) {find_odd = true; alp[i]--;}
        }
        if(!find_odd) ok = false;
        else{
            //H/2 + W/2個の奇数
            int need_minus2 = H/2 + W/2;
            rep(i, 26){
                if(alp[i] % 4 == 2){
                    need_minus2--;
                    alp[i] -= 2;
                }
                if(need_minus2 < 0 || alp[i] % 2 == 1) ok = false;
            }
            if(need_minus2 % 2 == 1) ok = false;
        }
        
    }
    else if(W % 2 == 0){
        //H, W両方偶数 ->全てが4の倍数である必要がある
        rep(i, 26) if(alp[i] % 4 != 0) ok = false;
    }
    else{
        //Wのみが奇数
        //計H/2回、任意のアルファベットカウンタから2を引いて(重複可)全てを4の倍数にする
        int need_minus2 = H/2;
        rep(i, 26){
            if(alp[i] % 4 == 2){
                need_minus2--;
                alp[i] -= 2;
            }
            if(need_minus2 < 0 || alp[i] % 2 == 1) ok = false;
        }
        if(need_minus2 % 2 == 1) ok = false;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}

void solve(){}