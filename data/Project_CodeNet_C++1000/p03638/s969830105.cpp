#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll h,w,n;
    cin >> h >> w >> n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++) cin >> a[i];
    vector<vector<ll>>ans(h,vector<ll>(w));
    ll turn=0,x=0,y=0;
    for(ll i=0;i<n;i++){
        while(a[i]>0){
            if(y>=w){
                turn=1;
                y=w-1;
                x++;
            }
            if(y<0){
                turn=0;
                y=0;
                x++;
            }
            ans[x][y]=i+1;
            if(turn==0) y++;
            else y--;
            a[i]--;
        }
    }
    
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}