#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n,l;
    cin >> n >> l;
    vector<ll> a(n);
    for(i = 0;i < n;++i){
        cin >> a.at(i);
    }
    stack<ll> ans;
    ll f = -1;
    for(i = 0;i < n-1;++i){
        if(a.at(i) + a.at(i+1) >= l){
            ans.push(i+1);
            f = i+1;
            break;
        }
    }
    if(f == -1){
        cout << "Impossible" << endl;
        return 0;
    }
    cout << "Possible" << endl;
    for(i = f+1;i < n;++i){
        ans.push(i);
    }
    for(i = f-1;i >= 1;--i){
        ans.push(i);
    }
    while(!ans.empty()){
        ll t = ans.top();
        ans.pop();
        cout << t << endl;
    }


    return 0;
}