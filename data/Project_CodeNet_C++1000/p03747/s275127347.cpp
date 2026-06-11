#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for(int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

int main() {
    ll n, l, t;
    cin >> n >> l >> t;
    t *= 2;
    l *= 2;
    ll x[n], w[n];
    ll cnt = 0;
    ll tt = t;
    rep(i,n){
        cin >> x[i] >> w[i];
        x[i] *= 2;
        if(w[i]==1)cnt++;
    }
    ll INF = 1001001001001001001;
    INF -= INF % l;
    if(cnt == 0 || cnt == n){
        rep(i,n){
            if(w[i] == 1){
                cout << (x[i] + t) % l / 2 << endl;
            }else{
                cout << (x[i] + INF - t) % l / 2 << endl;
            }
        }
        return 0;
    }
    int nex[n] = {};
    int w1 = -1, w2 = -1;

    drep(i,n){
        if(w[i] == 2){
            nex[i] = w2;
            w2 = i;
        }
    }
    rep(i,n){
        if(w[i] == 1){
            nex[i] = w1;
            w1 = i;
        }
    }
    rep(i,n){
        if(nex[i] == -1){
            if(w[i] == 1) nex[i] = w1;
            else nex[i] = w2;
        }
    }

    if(w[0] == 1) cnt = (n-cnt);
    ll cnt2 = cnt;
    cnt *= 2;
    cnt %= n;
    
    ll loop = t / l;
    ll now = 0;
    if(w[0] == 1){
        now += loop * cnt;
        now %= n;
    }else{
        now += loop * (n - cnt);
        now %= n;
    }

    t %= l;
    int half_flag = 0;
    if(t >= l/2){
        if(w[0] == 1){
            now += cnt2;
            now %= n;
        }else{
            now += (n - cnt2);
            now %= n;
        }
        t -= l/2;
        half_flag = 1;
    }

    /*
    rep(i,n) cout << nex[i] << ' ';
    cout << endl;
    */

    int ite = -1;
    int start = ite;
    if(w[0]==1){
        rep(i,n){
            if(w[i] == 2){
                ite = i;
                break;
            }
        }
        start = ite;
        while(true){
            ll diff = (x[ite] - x[0]) / 2;
            if(diff >= t){
                break;
            }else{
                now = (now + 1) % n;
                ite = nex[ite];
            }
            if(ite == start) break;
        }
    }else{
        drep(i,n){
            if(w[i] == 1){
                ite = i;
                break;
            }
        }
        start = ite;
        while(true){
            ll diff = (l - (x[ite] - x[0])) / 2;
            if(diff > t){
                break;
            }else{
                now = (now + n - 1) % n;
                ite = nex[ite];
            }
            if(ite == start) break;
        }
    }
    now %= n;

    ll fin[n] = {};
    ll fzero;
    rep(i,n){
        if(w[i] == 1){
            fin[i] = (x[i] + tt) % l / 2;
        }else{
            fin[i] = (x[i] + INF - tt) % l / 2;
        }
    }
    fzero = fin[0];
    sort(fin,fin+n);
    int zero = lower_bound(fin,fin+n,fzero) - fin;
    rep(i,n){
        cout << fin[(zero+i+n-now)%n] << endl;
    }
    return 0;
}


