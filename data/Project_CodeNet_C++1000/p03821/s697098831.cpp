#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>
#define all(a) a.begin(),a.end()

int main(){
    int n;
    cin >> n;
    vector<pair<ll, ll> > a(n);
    ll ans=0;

    for(int i=0; i<n; ++i){
        cin >> a[i].first >> a[i].second;
    }

    for(int i=n-1; i>=0; --i){
        a[i].first = a[i].first+ans;

        if(a[i].first % a[i].second == 0)
            continue;

        if(a[i].first > a[i].second){
            ll z = a[i].first/a[i].second + 1;
            ans += a[i].second * z - a[i].first;
        }
        else{
            ans += a[i].second - a[i].first;
        }
    }
    cout << ans;
}
