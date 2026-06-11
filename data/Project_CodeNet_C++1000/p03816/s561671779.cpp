#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    map<int, int> mp;
    rep(i, n) {
        int a;
        cin >> a;
        mp[a]++;
    }
    int rest = 0;
    for (auto p: mp) {
        if (p.second >= 2) {
            rest += p.second-1;
        }
    }
    if (rest%2==0) cout << mp.size() << endl;
    else cout << mp.size()-1 << endl;
    return 0;
}