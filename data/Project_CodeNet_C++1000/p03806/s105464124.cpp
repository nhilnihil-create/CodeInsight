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
    int N,Ma,Mb;
    cin>>N>>Ma>>Mb;
    vector<int> a(N),b(N),c(N);
    REP(i,N){
        cin>>a[i]>>b[i]>>c[i];
    }
    auto dp=make_vec<int>(41,401,401);
    REP(i,41){
        REP(j,401){
            REP(k,401){
                dp[i][j][k]=INF;
                if(j==0&&k==0) dp[i][j][k]=0;
            }
        }
    }

    REP(i,N){
        REP(j,401){
            REP(k,401){
                dp[i+1][j][k]=dp[i][j][k];
                if(j-a[i]>=0&&k-b[i]>=0) dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j-a[i]][k-b[i]]+c[i]);
            }
        }
    }

    int ans=INF;
    REP(i,40){
        REP2(j,1,401){
            REP2(k,1,401){
                if(Mb*j==Ma*k){
                    ans=min(ans,dp[N][j][k]);
                }
            }
        }
    }
    if(ans==INF){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }
    

}