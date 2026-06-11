#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int w, h, n; cin >> w >> h >> n;
    vector<pair<P,int>> query;
    P c1 = make_pair(0,0);
    P c2 = make_pair(w,h);
    rep(i,n){
        int x, y, a; cin >> x >> y >> a;
        if(a == 1){
            if(c1.first < x) c1.first = x;
        }else if(a == 2){
            if(c2.first > x) c2.first = x;
        }else if(a == 3){
            if(c1.second < y) c1.second = y;
        }else{
            if(c2.second > y) c2.second = y;
        }
    }
    int ans = max(c2.first - c1.first, 0) * max(c2.second - c1.second, 0);
    cout << ans << endl;
}