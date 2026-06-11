#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n,a,b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    for(i = 0;i < n;++i){
        cin >> v.at(i);
    }
    sort(all(v), greater<ll>());
    ll tmp = 0;
    for(i = 0;i < a;++i){
        tmp += v.at(i);
    }
    if(v.at(0) == v.at(a-1)){
        j = 0;
        while(j < n){
            if(v.at(j) != v.at(0)) break;
            else ++j;
        }
        vector<ll> nCk(j+1,1);
        for(i = 1;i <= j;++i){
            nCk.at(i) = nCk.at(i-1)*(j-i+1)/i;
        }
        
        ll num = 0;
        for(i = a;i <= min(j,b);++i){
            num += nCk.at(i);
        }
        cout << fixed << setprecision(10) << v.at(0) << endl;
        cout << num << endl;
    }else{
        ll left = 0, right = a-1;
        while(true){
            if(v.at(left) == v.at(a-1)) break;
            else ++left;
        }
        while(right < n){
            if(v.at(right) != v.at(a-1)) break;
            else ++right;
        }
        ll mn = right - left;
        vector<ll> nCk(mn+1,1);
        for(i = 1;i <= a - left;++i){
            nCk.at(i) = nCk.at(i-1)*(mn-i+1)/i;
        }
        double ans = (double)tmp/(double)a;
        cout << fixed << setprecision(10) << ans << endl;
        cout << nCk.at(a-left) << endl;
    }


    return 0;
}