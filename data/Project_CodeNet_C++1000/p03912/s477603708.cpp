#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    int x[n];
    int modm[m];
    fill_n(modm,m,0);
    rep(i,n){
        cin >> x[i];
        modm[x[i]%m]++;
    }
    sort(x,x+n);
    int pairnum[m];
    fill_n(pairnum,m,0);
    int streak = 1;
    rep(i,n-1){
        if(x[i]==x[i+1]) streak++;
        else{
            pairnum[x[i]%m]+=(streak/2);
            streak=1;
        }
    }
    pairnum[x[n-1]%m]+=(streak/2);
    int ans = 0;
    rep(i,(m/2)+1){
        if(i==0){
            ans+=(modm[0]/2);
            modm[0]%=2;
        }
        else if(i==m/2 && m%2==0){
            ans+=(modm[i]/2);
            modm[i]%=2;
        }
        else{
            int tmp = min(modm[i],modm[m-i]);
            ans+=tmp;
            modm[i]-=tmp;
            modm[m-i]-=tmp;
        }
    }
    rep(i,m) ans+=min(modm[i]/2,pairnum[i]);
    cout << ans << endl;
}