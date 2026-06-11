#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define LINF (ll)1e18
#define INF (int)1e9
#define ll_1e9 (ll)1e9
using namespace std;


int main(){
    ll h,w;
    cin >> h >> w;
    ll cnt[26] = {};

    char a[h][w];
    rep(i,0,h) rep(j,0,w) {
        cin >> a[i][j];
        cnt[a[i][j] - 'a']++;
    }

    if(h % 2 == 0 && w % 2 == 0){
        rep(i,0,26){
            if(cnt[i] % 4){
                cout << "No" << endl;
                break;
            }
            else if(i == 25) cout << "Yes" << endl;
        }
    }
    else if(h % 2 == 0 || w % 2 == 0){
        if(w % 2 == 0) swap(h,w);
        ll temp = 0;
        rep(i,0,26){
            if(cnt[i] % 2){
                cout << "No" << endl;
                return 0;
            }
            
            temp += cnt[i] / 4;
        }

        if(temp >= (w-1)*h/4) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else{
        ll temp = 0;
        bool flag = false;
        rep(i,0,26){
            if(cnt[i] % 2){
                if(flag){
                    cout << "No" << endl;
                    return 0;
                }
                flag = true;
            }
            
            temp += cnt[i] / 4;
        }

        if(temp >= (h-1)*(w-1)/4){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }

    return 0;
}
