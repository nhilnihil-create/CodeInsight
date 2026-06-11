#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

ll ans = 1LL<<60;
ll h,w;
vector<ll> s(3);

void f(){
    for(ll a=1;a<h;a++){
        if(h-a != 1){
            s[0] = a*w;
            s[1] = w*((h-a)/2);
            s[2] = h*w-s[0]-s[1];
            sort(all(s));
            ans = min(ans, s[2]-s[0]);
        }
        s[0] = a*w;
        s[1] = (h-a) * (w/2);
        s[2] = h*w-s[0]-s[1];
        sort(all(s));
        ans = min(ans, s[2]-s[0]);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>h>>w;
    f();
    swap(h,w);
    f();
    cout<<ans<<endl;
}