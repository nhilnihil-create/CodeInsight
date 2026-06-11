#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()

const string YES = "YES";
const string NO = "NO";

int main(){
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> net(n);
    REP(i, m){
        ll ai, bi;
        cin >> ai >> bi;
        ai--; bi--;
        net.at(ai).push_back(bi);
        net.at(bi).push_back(ai);
    }

    REP(i, n){
        if(net.at(i).size() % 2 == 1){
            cout << NO << endl;
            return 0;
        }
    }
    cout << YES << endl;
    return 0;
}
