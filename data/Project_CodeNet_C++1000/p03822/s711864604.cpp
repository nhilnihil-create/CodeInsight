#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n-1);i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(std::unique(all(x)), x.end());
typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9+7;
const ll LINF = 1e18;
const double PI=acos(-1);
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

vector<vector<int>> children;
int dfs(int now) {
    int m=sz(children[now]);
    if(m==0) {
        return 0;
    }
    vector<int> vec;
    for(int child:children[now]) {
        vec.push_back(dfs(child));
    }
    sort(all(vec),greater<int>());
    int ret=0;
    rep(i,m) chmax(ret,vec[i]+i+1);
    return ret;
}

int main() {
    int n;
    cin>>n;
    children.resize(n);
    for(int i = 1; i < n; i++) {
        int x;
        cin>>x;
        x--;
        children[x].push_back(i);
    }
    cout<<dfs(0)<<endl;
}