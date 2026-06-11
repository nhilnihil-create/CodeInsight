#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    rep(i, n){
        int a;
        cin >> a;
        mp[a]++;
    }

    vector<pair<ll, ll>> p;
    for(auto i = mp.begin(); i != mp.end(); i++){
        if(i->second > 1) p.push_back(make_pair(i->first, i->second)); 
    }
    
    if((int)p.size() < 2) cout << 0 << endl;
    else{
        sort(p.begin(), p.end(), greater<pair<ll, ll>>());
        if(p[0].second > 3) cout << p[0].first * p[0].first << endl;
        else cout << p[0].first * p[1].first << endl;
    }
}