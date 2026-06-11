#include <bits/stdc++.h>

#define REP(i,n) for(int i = 0; i < n; i++)
#define RREP(i, a, b) for (int i = a; i < (b); i++)
#define FOR(i, n) for (int i = n; i >= 0; i--)
using namespace std;
typedef long long ll;

int main(){
    int nmin = 1;
    ll n;
    cin >> n;
    ll custom[n];
    ll sell = 0;
    REP(i,n) cin >> custom[i];
    REP(i,n){
        if(nmin > custom[i]) continue;
        else if(nmin == custom[i]){
            nmin++;
            continue;
        }
        sell = sell + floor((custom[i] - 1)/double(nmin));
        if(nmin == 1) nmin++;
    }
    cout << sell << "\n";
    return 0;
}
