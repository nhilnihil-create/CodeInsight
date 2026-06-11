#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>
#define all(a) a.begin(),a.end()

int main(){
    ll n, k;
    cin >> n >> k;
    vector<pii> a(n);
    for(int i=0; i<n; ++i){
        cin >> a[i].first >> a[i].second;
    }
    sort(all(a));

    ll ans=a[0].first, z=0;
    for(int i=0; i<n; ++i){
        z+=a[i].second;

        if(z < k)
            continue;
        else{
            ans = a[i].first;
            break;
        }
    }
    cout << ans;
}
