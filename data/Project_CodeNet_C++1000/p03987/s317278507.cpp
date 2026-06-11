#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll niz[200005];
int levo[200005];
int desno[200005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
    }
    stack <int> stek;
    stek.push(0);
    for(int i=1; i<=n; i++){
        while(niz[stek.top()] > niz[i]) stek.pop();
        levo[i] = stek.top();
        stek.push(i);
    }
    while(!stek.empty()) stek.pop();
    stek.push(n+1);
    for(int i=n; i>=1; i--){
        while(niz[stek.top()] > niz[i]) stek.pop();
        desno[i] = stek.top();
        stek.push(i);
    }
    ll res = 0;
    for(int i=1; i<=n; i++){
        res += niz[i]*(i-levo[i])*(desno[i]-i);
    }
    cout << res;
    return 0;
}
