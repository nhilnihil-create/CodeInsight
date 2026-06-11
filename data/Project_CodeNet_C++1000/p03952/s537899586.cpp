//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const ll INF=1e+18;
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

//省略
using vi  = vector<int>;
using vii = vector<vector<int>>;
using vl  = vector<ll>;
using vll = vector<vector<ll>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int main(){
    int N,x;
    cin>>N>>x;
    if(x==1||x==2*N-1){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
        set<int> st;
        REP2(i,1,2*N) st.insert(i);
        vl ans(2*N-1,0);
        ans[N-2]=x-1;
        ans[N-1]=x;
        ans[N]=x+1;
        st.erase(x-1);
        st.erase(x);
        st.erase(x+1);
        REP(i,2*N-1){
            if(ans[i]!=0) continue;
            auto itr = st.begin();
            ans[i]=*itr;
            st.erase(itr);
        }
        REP(i,2*N-1) cout<<ans[i]<<endl;
        
    }
}