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
    int a,b,c,d,e,f; cin>>a>>b>>c>>d>>e>>f;
    // 到達可能な水の量
    set<int> wat;
    for(int x=0; x<=f; x++){
        for(int y=0; y<=f; y++){
            if(a*100*x+b*100*y <= f) wat.insert(a*100*x+b*100*y);
        }
    }
    // それぞれに対して砂糖を溶かせるだけ溶かし、最濃をつくる
    double deg = -1;
    pair<int, int> ans;
    for(auto w : wat){
        // 砂糖の限界量
        int cap = min(w*e / 100, f-w);
        // 作れる砂糖量が一番多いやつを全探索する
        int sugar = 0;
        for(int x=0; x<=f; x++){
            for(int y=0; y<=f; y++){
                if(c*x + d*y <= cap){
                    sugar = max(sugar, c*x + d*y);
                }
            }
        }
        // このときの濃度
        double deg2 = (double)100*sugar/(double)(w+sugar);
        // cerr<<w<<" "<<cap<<" "<<sugar<<" "<<deg2<<endl;
        if(deg<deg2){
            deg = deg2;
            ans = make_pair(sugar+w, sugar);
        }
    }
    cout<<ans.first<<" "<<ans.second<<endl;
}
// arc083_a.exe