#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=((n)-1);(i)>=0;(i)--)
#define itn int
#define all(x) (x).begin(),(x).end()
const long long INF = 1LL << 60;
const int MOD = 1000000007;
#define F first
#define S second
signed main(void){
    int h,w; cin>>w>>h;
    priority_queue <pair <int,int>, vector <pair <int,int> >, greater<pair <int,int> >> pq; //横0 縦1
    int ver = h+1, hor = w+1;
    int ans = 0;
    
    rep(i,w){
        int a; cin>>a;
        pq.push({a,0});
    }
    rep(i,h){
        int a; cin>>a;
        pq.push({a,1});
    }
    while(!pq.empty()){
        auto tmp = pq.top(); pq.pop();
        if(tmp.S){
            //cout<<tmp.F<<' '<<hor<<"tate"<<endl;
            ans += hor*tmp.F; ver--;
        }else{
            //cout<<tmp.F<<' '<<ver<<"横"<<endl;
            ans += ver*tmp.F; hor--;
        }
    }
    cout<<ans<<endl;
}
