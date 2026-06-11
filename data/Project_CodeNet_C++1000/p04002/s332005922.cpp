#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb emplace_back

signed main(){
    int h,w,n;
    cin>>h>>w>>n;
    set<pii> pos;
    rep(i,n){
        int x,y;
        cin>>y>>x;
        x--,y--;
        pos.insert(pii(y,x));
    }
    
    vector<int> c(10,0);
    set<pii> used;
    for(auto elm : pos){
        int y,x;
        tie(y,x) = elm;
        for(int i=-2;i<=0;i++){
            for(int j=-2;j<=0;j++){
                int ddy = y+i;
                int ddx = x+j;
                if( ddy<0 || ddx<0 || ddy+2>=h || ddx+2>=w || used.count(pii(ddy,ddx)) )continue;
                used.insert(pii(ddy,ddx));
                
                int sum = 0;
                rep(ii,3){
                    rep(jj,3){
                        if(pos.count(pii(ddy+ii,ddx+jj)))sum++;
                    }
                }
                c[sum]++;
            }
        }
    }
    rep(i,c.size()){
        if(i==0)cout<<(h-2)*(w-2)-used.size()<<endl;
        else cout<<c[i]<<endl;
    }
}
