#include<bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


using namespace std;
vector<int> ans;
vector<int> preans;
vector<int> G[1000000];
bool b[1000000];

void solve(int n) {
    ans.push_back(n);
    b[n] = true;
    rep(i, G[n].size()) {
        if (!b[G[n][i]]) {
            solve(G[n][i]);
            break;
        }
    }
}

void solve2(int n) {
    if (n != 0) preans.push_back(n);
    b[n] = true;
    rep(i, G[n].size()) {
        if (!b[G[n][i]]) {
            solve2(G[n][i]);
            break;
        }
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    rep(i, M){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    rep(i, N){
        b[i] = false;
    }
    solve(0);
    solve2(0);
    cout << ans.size() + preans.size() << endl;
    rep(i, preans.size()){
        cout << preans[preans.size()-i-1] + 1 << " ";
    }
    rep(i, ans.size()){
        cout << ans[i] + 1 << " ";
    }
    cout << endl;

}