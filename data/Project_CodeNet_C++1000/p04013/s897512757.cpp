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

ll dp[51][51][2510];

int main(){
    ll N,A;
    cin>>N>>A;
    vector<ll> x(N);
    REP(i,N) cin>>x[i];
    
    REP(i,51){
        REP(j,51){
            REP(k,2510){
                dp[i][j][k]=0;
                
            }
            
        }
    }

    dp[0][0][0]=1;

    REP(i,N){
        REP(j,i+1){
            REP(k,2510){
                if(k+x[i]>2500) continue;
                dp[i+1][j+1][k+x[i]]+=dp[i][j][k];
                dp[i+1][j][k]+=dp[i][j][k];
            } 
        }
    }

    ll ans=0;
    REP2(j,1,N+1){
        REP2(k,1,2510){
            if(k==A*j){
                ans+=dp[N][j][k];
            }
        } 
    }
    
    cout<<ans<<endl;
}