#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n,x;
    cin >> n >> x;
    if(x == 1 || x == 2*n-1){
        cout << "No" << endl;
        return 0;
    }
    vector<ll> ans(2*n-1,0);
    vector<bool> used(2*n,false);
    if(n == 2){
        if(x == 2){
            cout << "Yes" << endl;
            for(i = 1;i <= 3;++i){
                cout << i << endl;
            }
        }else{
            cout << "No" << endl;
        }
        return 0;
    }
    if(x != 2){
        ans.at(n-2) = x-1;
        used.at(x-1) = true;
        ans.at(n-1) = x;
        used.at(x) = true;
        ans.at(n) = x+1;
        used.at(x+1) = true;
        ans.at(n+1) = x-2;
        used.at(x-2) = true;
        ll now = 1;
        for(i = 0;i < 2*n-1;++i){
            if(!ans.at(i)){
                while(used.at(now)) ++now;
                ans.at(i) = now;
                used.at(now) = true;
            }
        }
        cout << "Yes" << endl;
        for(i = 0;i < 2*n-1;++i){
            cout << ans.at(i) << endl;
        }

    }else{
        ans.at(n-2) = x+1;
        used.at(x+1) = true;
        ans.at(n-1) = x;
        used.at(x) = true;
        ans.at(n) = x-1;
        used.at(x-1) = true;
        ans.at(n+1) = x+2;
        used.at(x+2) = true;
        ll now = 1;
        for(i = 0;i < 2*n-1;++i){
            if(!ans.at(i)){
                while(used.at(now)) ++now;
                ans.at(i) = now;
                used.at(now) = true;
            }
        }
        cout << "Yes" << endl;
        for(i = 0;i < 2*n-1;++i){
            cout << ans.at(i) << endl;
        }
    }

    return 0;
}