#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using ll = long long;
#define int long long
signed main(void){
    int n,a,b; cin>>n>>a>>b;
    
    vector <int> h(n); 
    rep(i,n) cin>>h[i];
    int l = -1, r = 1145141919;
    while(abs(r-l)>1){
        int mid = (r+l)/2; //midは回数
        int k = mid; //k回aのダメージを与えるのが許される
        int need = 0;
        rep(i,n){
            int hp = h[i]- b*k;
            //cout<<hp<<endl;
            if(hp>0){
                need += hp/(a-b) + (hp%(a-b)!=0);
            }
        }
        //cout<<need<<endl;
        k -= need;
        if(k>=0) r = mid;
            else l = mid;
    }
    cout<<r<<endl;
}
