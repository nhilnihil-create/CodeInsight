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
    int h,w;cin>>h>>w;
    vector<string> vs;
    rep(i,h){
        string t;cin>>t;
        vs.push_back(t);
    }
    rep(i,h){
        cout<<vs[i]<<endl;
        cout<<vs[i]<<endl;
    }
    return 0;
}