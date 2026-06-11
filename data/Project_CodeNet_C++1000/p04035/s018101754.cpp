#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
typedef long long ll;
int main(){
    ll n, l;
    cin >> n >> l;
    vector<ll> a(n), uni(n-1);
    ll las = -1;
    rep(i,n){
        cin >> a[i];
        if(i > 0){
            uni[i-1] = a[i] + a[i-1];
            if(uni[i-1] >= l)las = i-1;
        }
    }
    
    if(las == -1){
        cout << "Impossible" << endl;
        return 0;
    }

    cout << "Possible" << endl;
    rep(i,las)cout << i+1 << endl;
    for(int i = n-2; i >= las; i--)cout << i+1 << endl;
    return 0;
}