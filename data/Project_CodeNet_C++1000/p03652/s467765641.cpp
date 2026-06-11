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
    auto a=make_vec<int> (n,m);
    rep(i,n) rep(j,m){
        cin>>a[i][j];
        a[i][j]--;
    }
    
    int ans=INF;
    vector<bool> sports(m,true);
    rep(i,m){
        vector<int> sanka(m);
        
        rep(j,n){
            int now=0;
            while(now<m && !sports[a[j][now]]) now++;
            sanka[a[j][now]]++;
        }
        
        int tmp;
        int maxi=0;
        rep(j,m){
            if(sanka[j]>=maxi){
                tmp=j;
                maxi=sanka[j];
            }
        }
        sports[tmp]=false;
        ans=min(ans,maxi);
    }
    cout<<ans<<endl;
}
