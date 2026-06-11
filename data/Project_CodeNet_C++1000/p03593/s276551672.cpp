#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;


int main()
{
    ll i,j;
    ll h,w;
    cin >> h >> w;
    vector<string> a(h);
    map<char, ll> mp;
    for(i = 0;i < h;++i){
        cin >> a.at(i);
        rep(j,w){
            ++mp[a.at(i).at(j)];
        }
    }
    if(h%2 == 0 && w%2 == 0){
        for(auto x:mp){
            if(x.second%4){
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
        return 0;
    }else if(h*w % 2 == 0 && (h%2 || w%2)){
        ll tmp = 0;
        for(auto x:mp){
            if(x.second%4 != 0 && x.second%4 != 2){
                cout << "No" << endl;
                return 0;
            }
            if(x.second%4 == 2) ++tmp;
        }
        ll num;
        if(h%2 == 0) num = h;
        else num = w;
        if(tmp > num/2) cout << "No" << endl;
        else cout << "Yes" << endl;
        return 0;
    }else{
        ll tmp1 = 0;
        ll tmp2 = 0;
        for(auto x:mp){
            if(x.second%4 == 3){
                cout << "No" << endl;
                return 0;
            }
            if(x.second%4 == 1) ++tmp1;
            else if(x.second%4 == 2) ++tmp2;
        }
        if(tmp1 > 1 || tmp2 > h+w-1) cout << "No" << endl;
        else cout << "Yes" << endl;
        return 0;
    }

    return 0;
}