#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U> using Pa = pair<T, U>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll W,H;
    cin >> W >> H;
    struct edge{
        int i,j;
        ll c;
    };
    vec<edge> E;
    for(int i=0;i<W;i++){
        ll c;
        cin >> c;
        E.push_back({i,-1,c});
    }
    for(int i=0;i<H;i++){
        ll c;
        cin >> c;
        E.push_back({-1,i,c});
    }
    ll cntW = W+1,cntH = H+1;
    sort(E.begin(),E.end(),[](edge& a,edge& b){
        return a.c<b.c;
    });
    ll ans = 0;
    for(auto& e:E){
        if(e.j==-1){
            ans += e.c*cntH;
            cntW--;
        }else{
            ans += e.c*cntW;
            cntH--;
        }
    }
    cout << ans << "\n";
}