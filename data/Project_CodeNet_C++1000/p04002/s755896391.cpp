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
    int h,w,n;
    cin>>h>>w>>n;
    
    map<pair<int,int>,bool> black;
    vector<pair<int,int>> ab(n);
    rep(i,n){
        int a,b;
        cin>>a>>b;
        a--;b--;
        black[make_pair(a,b)]=true;
        ab[i]=make_pair(a,b);
    }
    
    map<pair<int,int>,bool> checked;
    vector<int> ans(10);
    rep(i,n){
        int a,b;
        tie(a,b)=ab[i];
        
        rep(j,3){
            rep(k,3){
                int na=a-j;
                int nb=b-k;
                if(na<0 || nb<0) continue;
                if(na+2>=h || nb+2>=w) continue;
                if(checked[make_pair(na,nb)]) continue;
                checked[make_pair(na,nb)]=true;
                
                int cnt=0;
                rep(y,3){
                    rep(x,3){
                        if(black[make_pair(na+y,nb+x)]) cnt++;
                    }
                }
                ans[cnt]++;
            }
        }
    }
    
    int sum=0;
    FOR(i,1,9) sum+=ans[i];
    ll zero=(ll)(h-2)*(w-2)-sum;
    cout<<zero<<endl;
    FOR(i,1,9) cout<<ans[i]<<endl;
    
}

