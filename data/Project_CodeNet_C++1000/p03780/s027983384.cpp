#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

bitset <5005> pref[5005];
bitset <5005> suf[5005];
int niz[5005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, k;
    cin >> n >> k;
    pref[0][0] = 1;
    suf[n+1][0] = 1;
    ll ukup = 0;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        ukup += niz[i];
        pref[i] = pref[i-1] | (pref[i-1] << niz[i]);
    }
    if(ukup < k){
        cout << n;
        return 0;
    }
    for(int i=n; i>=1; i--){
        suf[i] = suf[i+1] | (suf[i+1] << niz[i]);
    }
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(niz[i] >= k){
            cnt++;
            continue;
        }
        int r = k-1;
        int l = k-niz[i];
        int tren = 0;
        for(int j=l; j<=r; j++) if(suf[i+1][j]) tren++;
        int r1 = r;
        for(int j=0; j<=r1; j++){
            if(tren && pref[i-1][j]){
                cnt++;
                break;
            }
            if(l > 0){
                l--;
                if(suf[i+1][l]) tren++;
                if(suf[i+1][l+1]) tren--;
            }
            if(r > 0){
                r--;
                if(suf[i+1][r]) tren++;
                if(suf[i+1][r+1]) tren--;
            }
        }
    }
    cout << n-cnt;
    return 0;
}
