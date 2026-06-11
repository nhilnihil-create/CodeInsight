#include <bits/stdc++.h>

typedef long long   ll;
typedef long double ld;
using namespace std;
const int MOD=1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }


    int chk[(n+1)/2]={};
    if(n%2==0){
        for(int i = 0; i < n; i++) {
            chk[(a[i]-1)/2]++;
        }
    }
    else{
        chk[0]++;
        for(int i = 0; i < n; i++) {
            chk[a[i]/2]++;
        }
    }

    bool jud=true;
    for(int i = 0; i < (n+1)/2; i++) {
        if(chk[i]!=2) jud=false;
    }
    if(jud){
        ll ans=1;
        for(int i = 0; i < n/2; i++) {
            ans=ans*2%MOD;
        }
        cout << ans << "\n";
    }
    else cout << 0 << "\n";

    return 0;
}