#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

int main() {
    ll l = 100000000000;
    ll r = 999999999999;
    while(l<r){
        ll m = (l + r) / 2;
        cout << "? " << m << endl;
        fflush(stdout);
        char s; cin >> s;
        if(s == 'Y'){
            r = m;
        }else{
            l = m + 1;
        }
    }

    int ans[20] = {};
    while(r % 10 == 0)r /= 10;
    int keta = 0;
    rep(i,20){
        if(r > 0)keta++;
        ans[i] = r % 10;
        r /= 10;
    }

    int nine = 1;
    rep(i,keta){
        if(ans[i] != 9)nine = 0;
    }

    if(nine == 1){
        ll ten = 100000000000000;
        int flag = 0;
        drep(i,15){
            if(i == 0)break;
            cout << "? " << ten << endl;
            ten /= 10;
            fflush(stdout);
            char s; cin >> s;
            if(s == 'Y'){
                flag = i;
                break;
            }
        }
        cout << "! ";
        if(flag == 0){
            rep(i,keta){
                cout << '9';
            }
        }else{
            rep(i,flag+1){
                cout << ans[i];
            }
        }
        cout << endl;
        fflush(stdout);
        return 0;
    }

    int flag = 0;
    ll ten = 100000000000000;
    drep(i,15){
        if(i == 0)break;
        cout << "? " << ten - 1 << endl;
        ten /= 10;
        fflush(stdout);
        char s; cin >> s;
        if(s == 'N'){
            flag = i;
            break;
        }
    }

    cout << "! ";
    rep(i,flag+1){
        if(keta - 1 - i < 0){
            cout << '0';
        }else{
            cout << ans[keta - 1 - i];
        }
        
    }
    cout << endl;
    fflush(stdout);
    return 0;
}
 
 
