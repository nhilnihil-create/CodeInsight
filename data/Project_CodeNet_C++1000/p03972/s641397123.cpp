#include <bits/stdc++.h>

#define REP(i,n) for(int i = 0; i < n; i++)
#define RREP(i, a, b) for (int i = a; i < (b); i++)
#define FOR(i, n) for (int i = n; i >= 0; i--)
using namespace std;
typedef long long ll;
vector<pair<ll, ll> > pack;
ll w, h;


int main(){
    cin >> w >> h;
    ll wholescore = 0;
    REP(i, w){
        ll tmp;
        cin >> tmp;
        wholescore = wholescore + tmp * (h + 1);
        pack.push_back(pair<ll, ll>(tmp, 1));
    }
    REP(i, h){
        ll tmp;
        cin >> tmp;
        wholescore = wholescore + tmp * (w + 1);
        pack.push_back(pair<ll, ll>(tmp, 2));
    }
    sort(pack.begin(), pack.end());
    ll pmax = w, qmax = h, maxsum = w * h, sum = 0, delsum = 0;
    FOR(i, pack.size() - 1){
        int type = pack[i].second;
        if(type == 2){
            qmax--;
            delsum = delsum + pmax * pack[i].first;
            sum = sum + pmax;
            //cout << pack[i].first << "*" << pmax << "\n";
        }
        else{
            pmax--;
            delsum = delsum + qmax * pack[i].first;
            sum = sum + qmax;
            //cout << pack[i].first << "*" << qmax << "\n";
        }
        if(sum >= maxsum){
            break;
        }
    }
    cout << wholescore - delsum << "\n";
    return 0;
}
