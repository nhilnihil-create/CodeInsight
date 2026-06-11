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
    ll N,M;
    cin>>N>>M;
    vector<queue<ll>> A(N);
    REP(i,N){
        REP(j,M){
            ll a;
            cin>>a;
            a--;
            A[i].push(a);
        }
    }

    set<ll> st;
    REP(i,M) st.insert(i);

    ll ans=N;
    REP(i,M){
        vector<ll> cnt(M,0);
        REP(i,N){
            ll a=A[i].front();
            cnt[a]++;
        }

        ll idx=0;
        ll tmp=0;
        REP(i,M){
            if(cnt[i]>tmp){
                tmp=cnt[i];
                idx=i;
            }
        }

        ans=min(ans,tmp);

        st.erase(idx);
        REP(i,N){
            while(!A[i].empty()){
                ll a=A[i].front();
                if(st.count(a)) break;
                else A[i].pop();
            }
        }
    }
    cout<<ans<<endl;


}