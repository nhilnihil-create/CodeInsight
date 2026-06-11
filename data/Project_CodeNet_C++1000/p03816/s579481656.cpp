#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vll = vector<long long>;

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vi a(n);
    rep(i, n) cin >> a[i];
    map<int, int> mp;

    rep(i, n){
        mp[a[i]] = 0;
    }

    rep(i, n){
        mp[a[i]]++;
    }

    int cnt = 0;

    for(auto itr=mp.begin(); itr!=mp.end(); ++itr){
        if(itr->second>=3){
            if(itr->second%2==0){
                itr->second = 2;
            }else{
                itr->second = 1;
            }
        }

        if(itr->second==2){
            cnt++;
        }
    }

    if(cnt%2==0){
        cout << mp.size() << endl;
    }else{
        cout << mp.size() - 1 << endl;
    }

}