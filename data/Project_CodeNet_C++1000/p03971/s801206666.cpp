#include<bits/stdc++.h>
using namespace std;
#define rep(i, c) for(ll i = 0; i < (ll)c; i++)
#define ll long long
#define upd_max(maxer, updater) if (maxer < updater) maxer = updater;
#define upd_min(miner, updater) if (miner > updater) miner = updater;
const int inf = 1000000000; // 10^9

int main(){
    string s;
    ll n, a, b, kaigai = 0, kokunai = 0;

    cin >> n >> a >> b >> s;

    rep(i, n){
        if(s[i] == 'a'){
            if(kokunai + kaigai < a + b){
                cout << "Yes" << endl;
                kokunai++;
            }
            else cout << "No" << endl;
        }
        else if(s[i] == 'b'){
            if(kokunai + kaigai < a + b && kaigai < b){
                cout << "Yes" << endl;
                kaigai++;
            }
            else cout << "No" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }

    return 0;
}