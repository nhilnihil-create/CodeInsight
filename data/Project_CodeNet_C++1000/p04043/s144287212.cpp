#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    vector<ll> a(3);
    for(i = 0;i < 3;++i){
        cin >> a.at(i);
    }
    sort(all(a));
    if(a.at(0) == 5 && a.at(1) == 5 && a.at(2) == 7){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}