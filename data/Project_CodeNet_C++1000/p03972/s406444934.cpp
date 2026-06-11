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
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
int main(){
    int w,h;
    cin>>w>>h;
    vector<pair<int,int>> vec(w+h);
    rep(i,w){
        int p;
        cin>>p;
        vec[i]=make_pair(p,0);
    }
    rep(i,h){
        int q;
        cin>>q;
        vec[i+w]=make_pair(q,1);
    }
    sort(all(vec));
    
    ll ans=0;
    int a=w+1,b=h+1;
    for(auto x:vec){
        int cost,shu;
        tie(cost,shu)=x;
        if(shu==0){
            ans+=(ll)cost*b;
            a--;
        }
        else{
            ans+=(ll)cost*a;
            b--;
        }
    }
    cout<<ans<<endl;
}

