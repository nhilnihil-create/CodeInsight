#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a[100];
    int cnt[100] = {0};
    cin >> n;
    int mn = n, mx = 0;
    for(int i=0;i<n;++i){
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
        ++cnt[a[i]];
    }
    if(mx % 2){
        if(cnt[mn] != 2) goto l_ng;
        for(int i=mn+1;i<=mx;++i){
            if(cnt[i] == 0) goto l_ng;
        }
        goto l_ok;
    }else{
        if(cnt[mn] != 1) goto l_ng;
        for(int i=mn+1;i<=mx;++i){
            if(cnt[i] == 0) goto l_ng;
        }
        goto l_ok;
    }
l_ng:
    cout << "Impossible" << endl;
    return 0;
l_ok:
    cout << "Possible" << endl;
    return 0; 
}