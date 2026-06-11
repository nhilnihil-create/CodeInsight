#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n-1);i>=0;i--)
#define FOR(i,n,m) for(int i=n;i<=(int)(m);i++)
#define RFOR(i,n,m) for(int i=(int)(n);i>=m;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using namespace std;
vector<int> dy={1,0,-1,0};
vector<int> dx={0,1,0,-1};
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
int main(){
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>> children(n);
    deque<int> ans;
    vector<bool> check(n,false);
    
    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--;b--;
        if(i==0){
            ans.push_back(a);
            ans.push_back(b);
            check[a]=true;
            check[b]=true;
        }
        children[a].push_back(b);
        children[b].push_back(a);
    }
    
    while(true){
        int x=ans.front();
        int y=ans.back();
        
        bool ok=true;
        
        for(int child:children[x]){
            if(!check[child]) ok=false;
        }
        for(int child:children[y]){
            if(!check[child]) ok=false;
        }
        
        if(ok){
            cout<<sz(ans)<<endl;
            for(int k:ans) cout<<k+1<<endl;
            return 0;
        }
        
        bool go=false;
        for(int child:children[x]){
            if(!check[child]) {
                check[child]=true;
                ans.push_front(child);
                go=true;
                break;
            }
        }
        
        if(go) continue;
        
        for(int child:children[y]){
            if(!check[child]) {
                check[child]=true;
                ans.push_back(child);
                break;
            }
        }
        
    }
    
}


