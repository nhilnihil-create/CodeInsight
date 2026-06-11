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

int main(){
    ll N;
    cin>>N;
    vector<ll> a(3*N);
    vector<ll> L(N+1),R(N+1);
    REP(i,3*N) cin>>a[i];
    priority_queue<ll,vector<ll>,greater<ll>> zenhan;
    priority_queue<ll> kouhan;
    ll tmp=0;
    REP(i,N){
        tmp+=a[i];
        zenhan.push(a[i]);
    }
    L[0]=tmp;
    tmp=0;
    REP(i,N){
        tmp+=a[3*N-i-1];
        kouhan.push(a[3*N-i-1]);
    }
    R[N]=tmp;
    ll tmp_a;
    REP2(i,1,N+1){
        //前半
        tmp_a=zenhan.top();
        if(a[N-1+i]>tmp_a){
            zenhan.pop();
            zenhan.push(a[N-1+i]);
            L[i]=L[i-1]+a[N-1+i]-tmp_a;
        }else{
            L[i]=L[i-1];
        }

        //後半
        tmp_a=kouhan.top();
        if(a[2*N-i]<tmp_a){
            kouhan.pop();
            kouhan.push(a[2*N-i]);
            R[N-i]=R[N-i+1]+a[2*N-i]-tmp_a;
        }else{
            R[N-i]=R[N-i+1];
        }
    }

    ll ans=-INF;
    REP(i,N+1){
        ans=max(ans,L[i]-R[i]);
    }
    cout<<ans<<endl;

}