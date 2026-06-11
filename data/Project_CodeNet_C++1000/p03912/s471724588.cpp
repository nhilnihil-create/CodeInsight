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
    
    vector<int> x(n);
    map<int,int> mp;
    rep(i,n) {
        cin>>x[i];
        mp[x[i]]++;
    }
    
    vector<pair<int,int>> vec(m,make_pair(0,0)); //vec[i]->(mod mがiになるxの個数,その中の同じ整数のペアの個数)のpair
    rep(i,n){
        vec[x[i]%m].first++;
        if(mp[x[i]]>1){
            vec[x[i]%m].second+=mp[x[i]]/2;
            mp[x[i]]=0;
        }
    }
    
    //for(auto p:vec) cout<<p.first<<" "<<p.second<<endl;
    
    int ans=0;
    ans+=vec[0].first/2;
    if(m%2==0) ans+=vec[m/2].first/2;
    
    FOR(i,1,(m-1)/2){
        auto a=vec[i];
        auto b=vec[m-i];
        
        if(a>=b){
            ans+=b.first;
            ans+=min((a.first-b.first)/2,a.second);
        }
        else{
            ans+=a.first;
            ans+=min((b.first-a.first)/2,b.second);
        }
        
    }
    
    cout<<ans<<endl;
    
}


