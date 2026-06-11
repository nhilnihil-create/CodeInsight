#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main (){
    int w,h;
    cin >> w >> h;
    vector< pair<ll,int> > vp;
    for(int i=0;i<w;i++){
        ll p;
        cin >> p;
        vp.push_back(make_pair(p,0));
    }
    for(int i=0;i<h;i++){
        ll q;
        cin >> q;
        vp.push_back(make_pair(q,1));
    }
    sort(vp.begin(),vp.end());
    int pos = 0;
    ll ans = 0;
    while(1){
        if(w==0&&h==0)
            break;
        if(vp.size()<=pos) break;
        if(vp[pos].second == 0&&w>=1){
            w--;
            ans += vp[pos].first*(h+1);
        }
        if(vp[pos].second == 1&&h>=1){
            h--;
            ans += vp[pos].first*(w+1);
        }
        pos++;
    }
    cout<<ans<<endl;
    return 0;
}