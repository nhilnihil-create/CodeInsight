#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <math.h>
#include <complex>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <functional>
#include <assert.h>
#define int long
#define ll long long
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define SZ(x) x.size()
#define fi first
#define se second
const int INF = 1e9;
using namespace std;

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout<<fixed<<setprecision(20);

    int H,W; cin >> H >> W;
    map<char,int> m;
    rep(i,H) rep(j,W){
        char c; cin >> c;
        m[c]++;
    }
    int cnt2 = 0, cnt1 = 0;
    for(auto a:m){
        if(a.se%4==1){
            cnt1++;
        } else if(a.se%4==2){
            cnt2++;
        } else if(a.se%4==3){
            cnt1++; cnt2++;
        }
    }
    cnt2*=2;
    if(H%2 && W%2){
        cnt1-=1;
        cnt2-=H+W-2;
    } else if(H%2){
        cnt2-=W;
    } else if(W%2){
        cnt2-=H;
    }
    if(cnt1 == 0 && cnt2 <= 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}
