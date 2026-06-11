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
    ll n;
    cin>>n;
    vector<ll> a(n);
    ll sum=0;
    ll ans=0;
    REP(i,n) cin>>a[i];
    //偶数+
    REP(i,n){
        sum+=a[i];
        if(i%2==0&&sum<0){
            ans+=abs(sum)+1;
            sum=1;
        }else if(i%2==1&&sum>0){
            ans+=abs(sum)+1;
            sum=-1;
        }else if(sum==0){
            ans++;
            if(i%2==0){
                sum++;
            }else{
                sum--;
            }
        }
    }

    sum=0;
    ll ans2=0;
    //偶数-
    REP(i,n){
        sum+=a[i];
        if(i%2==1&&sum<0){
            ans2+=abs(sum)+1;
            sum=1;
        }else if(i%2==0&&sum>0){
            ans2+=abs(sum)+1;
            sum=-1;
        }else if(sum==0){
            ans2++;
            if(i%2==1){
                sum++;
            }else{
                sum--;
            }
        }
    }
    ans=min(ans,ans2);
    cout<<ans<<endl;
}