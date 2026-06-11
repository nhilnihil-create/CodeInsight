#include <bits/stdc++.h>

typedef long long   ll;
typedef long double ld;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(),a.end());

    int idx=n-2;
    ll ref=a[n-1];
    ll ls=0;
    bool flag=false;
    while(idx>=0) {
        if(a[idx]==ref){
            if(flag){
                cout << ref*ls << "\n";
                return 0;
            }
            ls=ref;
            flag=true;
            ref=a[idx-1];
            idx--;
        }
        else ref=a[idx];
        idx--;
    }
    cout << "0" << "\n";
    return 0;
}