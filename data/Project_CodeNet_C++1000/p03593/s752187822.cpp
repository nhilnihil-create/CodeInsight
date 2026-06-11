#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

int main(){
    ll H, W;
    cin >> H >> W;

    map<char, ll> rec;
    rep(h, 0, H){
        string a;
        cin >> a;
        rep(w, 0, W){
            rec[a[w]]++;
        }
    }

    if(H % 2 == 0 && W % 2 == 0){
        for(auto r : rec){
            if(r.second % 4 != 0){
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
    }else if(H % 2 == 1 && W % 2 == 1){
        ll num = 0;
        for(auto r : rec){
            if(r.second % 2 == 1){
                rec[r.first]--;
                num++;
            }
        }
        if(num != 1){
            cout << "No" << endl;
            return 0;
        }
        num = 0;
        for(auto r : rec){
            if(r.second % 4 == 2){
                rec[r.first] -= 2;
                num += 2;
            }        
        }
        if(num > (H-1) + (W-1) || ((H-1) + (W-1) - num) % 4 != 0){
            cout << "No" << endl;
            return 0;
        }
        cout << "Yes" << endl;
    }else{
        ll num = 0;
        for(auto r : rec){
            if(r.second % 2 == 1){
                rec[r.first]--;
                num++;
            }
        }
        if(num != 0){
            cout << "No" << endl;
            return 0;
        }
        num = 0;
        for(auto r : rec){
            if(r.second % 4 == 2){
                rec[r.first] -= 2;
                num += 2;
            }        
        }
        if(H % 2 == 0){
            if(num > H || (H - num) % 4 != 0){
                cout << "No" << endl;
                return 0;
            }
            cout << "Yes" << endl;
        }else{
            if(num > W || (W - num) % 4 != 0){
                cout << "No" << endl;
                return 0;
            }
            cout << "Yes" << endl;
        }
    }

    return 0;
}