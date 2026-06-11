#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m; cin>>n>>m;
    map<int,int> mp;
    rep(i, m){
        int a,b; cin>>a>>b;
        mp[a]++;
        mp[b]++;
    }
    for(auto a : mp){
        if(a.second % 2 == 1){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}