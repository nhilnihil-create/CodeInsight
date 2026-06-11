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
    int N;
    cin>>N;
    vector<ll> T(N),A(N);
    REP(i,N) cin>>T[i];
    REP(i,N) cin>>A[i];
    
    vector<ll> difT(N,-1),difA(N,-1);

    difT[0]=T[0];
    difA[N-1]=A[0];
    REP2(i,1,N){
        if(T[i-1]!=T[i]){
            difT[i]=T[i];
        }
    }

    REPD2(i,N-2,-1){
        if(A[i]!=A[i+1]){
            difA[i]=A[i];
        }
    }

    ll ans=1;
    bool ok=true;
    REP(i,N){
        if(difT[i]!=-1&&difA[i]!=-1){
            if(difT[i]!=difA[i]) ok=false;
            if(difT[i]>A[i]) ok=false;
        }

        if(difT[i]!=-1&&difA[i]==-1){
            if(difT[i]>A[i]) ok=false;
        }

        if(difT[i]==-1&&difA[i]!=-1){
            if(difA[i]>T[i]) ok=false;
        }

        if(difT[i]==-1&&difA[i]==-1){
            ans*=min(A[i],T[i]);
            ans%=MOD;
        }
    }
    if(ok) cout<<ans<<endl;
    else cout<<0<<endl;


}