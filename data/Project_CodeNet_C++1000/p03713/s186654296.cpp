#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main () {
    ll h,w;
    cin >> h >> w;
    ll ans = 1e18;
    ll h1,h2,h3;
    ll w1,w2,w3;
    ll s1,s2,s3;
    ll maxs,mins;
    auto calc_square = [&](){
        s1 = h1*w1; 
        s2 = h2*w2;
        s3 = h3*w3;
    };
    auto calc_tmp = [&](){
        maxs = max({s1,s2,s3});
        mins = min({s1,s2,s3});
        ans = min(ans,maxs-mins);
    };
    //まず横線を引く
    for(int i = 1;i<=h-1;i++) {
        //横線を引く
        h1 = i;
        h2 = (h-h1)/2;
        h3 = (h-h1)-h2;
        w1 = w;
        w2 = w;
        w3 = w;
        calc_square();
        calc_tmp();
        //縦線を引く
        h2 = h-h1;
        h3 = h-h1;
        w2 = w/2;
        w3 = w-w2;
        calc_square();
        calc_tmp();
    }
    //最初に縦線を引く場合
    for(int i = 1;i<=w-1;i++) {
        //横線を引く
        h1 = h;
        h2 = h/2;
        h3 = h-h2;
        w1 = i;
        w2 = w-w1;
        w3 = w-w1;
        calc_square();
        calc_tmp();
        //縦線を引く
        h1 = h;
        h2 = h;
        h3 = h;
        w1 = i;
        w2 = (w-w1)/2;
        w3 = (w-w1)-w2;
        calc_square();
        calc_tmp();
    }
    cout << ans << endl;
}