#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll h,w,n;
    cin >> h >> w >> n;
    map<pair<ll,ll>,ll> mp;
    for(int i = 0;i < n;i ++){
        ll a,b;
        cin >> a >> b;
        a --;b --;
        for(int i = -1;i < 2;i ++){
            for(int j = -1;j < 2;j ++){
                ll y=a+i,x=b+j;
                if((y-1)*(h-2-y)>=0&&(x-1)*(w-2-x)>=0) mp[make_pair(y,x)] ++;
            }
        }
    }
    for(int i = 0;i < 10;i ++){
        ll ans=0;
        for(auto ite = mp.begin();ite != mp.end();++ite){
            if(ite->second==i) ans ++;
        }
        if(!i) cout << (h-2)*(w-2)-mp.size() << endl;
        else cout << ans << endl;
    }
    return 0;
}