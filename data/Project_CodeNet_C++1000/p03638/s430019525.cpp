#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll h,w;
ll n;
ll a[10005];
ll b[10005];
ll res[111][111];

int main(){
    cin >> h >> w;
    cin >> n;
    b[0]=0;
    for(ll i=0;i<n;i++){
        cin >> a[i];
        b[i+1]=b[i]+a[i];
    }
    ll count=0;
    ll k=1;
    for(ll i=0;i<h;i++){
        if(i%2==0){
            for(ll j=0;j<w;j++){
                count++;
                if(count<=b[k]) res[i][j]=k;
                else if(count>b[k]){
                    k++;
                    res[i][j]=k;
                }
            }
        }
        else if(i%2==1){
            for(ll j=w-1;j>=0;j--){
                count++;
                if(count<=b[k]) res[i][j]=k;
                else if(count>b[k]){
                    k++;
                    res[i][j]=k;
                }
            }
        }
    }
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            if(j!=w-1) cout << res[i][j] << " ";
            else cout << res[i][j] << endl;
        }
    }
    return 0;
}  
