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

    ll a_min=INF;
    bool ok=true;

    REP(i,N){
        cin>>a[i];
        a_min=min(a_min,a[i]);
    }
    REP(i,N){
        if(a[i]-a_min>=2) ok=false;
    }

    if(ok){
        ll m=0;
        ll n=0;
        ll k=a_min;
        REP(i,N){
            if(a[i]==k) n++;
            else m++;
        }
        if(m==0){
            if(N<2*k&&N!=k+1) ok=false;
        }else{
            if(k<n) ok=false;
            if(m==1) ok=false;
            if(m<2*(k+1-n)) ok=false;
        }
    }
    

    if(ok){
        
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

}