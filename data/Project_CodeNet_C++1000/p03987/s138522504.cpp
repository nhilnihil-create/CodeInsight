//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const int INF=1e+9;
const int MOD=1e+9+7;

//REPマクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define REP2(i,a,b) for(ll i=a;i<(ll)(b);i++)
#define REPD2(i,a,b) for(ll i=a;i>(ll)(b);i--)

// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

//vectorの扱い
#define ALL(x) (x).begin(),(x).end() //sortなどの引数省略
#define SIZE(x) ((ll)(x).size()) //size
#define MAX(x) *max_element(ALL(x)) //最大値
#define MIN(x) *min_element(ALL(x)) //最小値

int main(){
    ll N;
    cin>>N;
    vector<ll> a(N);
    REP(i,N) cin>>a[i];
    vector<ll> R(N,0),L(N,0);
    ll cnt=0;
    ll num=0;

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> que;
    set<ll> st;
    st.insert(-1);
    st.insert(N);
    REP(i,N){
        que.push(make_pair(a[i],i));
    }

    ll ans=0;

    while(!que.empty()){
        pair<ll,ll> p=que.top();
        ll num=p.first;
        ll idx=p.second;
        que.pop();
        auto itr=st.upper_bound(idx);
        ll r=*itr-idx;
        itr--;
        ll l=idx-*itr;
        ans+=num*l*r;
        st.insert(idx);
    }
    
    cout<<ans<<endl;
}