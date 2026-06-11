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
     string S,T;
     cin>>S;
     cin>>T;
     ll NS=S.size();
     ll NT=T.size();
     vector<ll> AS(NS+1,0),BS(NS+1,0),AT(NT+1,0),BT(NT+1,0);
     REP(i,NS){
         AS[i+1]=AS[i];
         BS[i+1]=BS[i];
         if(S[i]=='A') AS[i+1]++;
         else BS[i+1]++;
     }

     REP(i,NT){
         AT[i+1]=AT[i];
         BT[i+1]=BT[i];
         if(T[i]=='A') AT[i+1]++;
         else BT[i+1]++;
     }

    ll q;
    cin>>q;
    vector<string> ans(q);
    REP(i,q){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        ll A_T=AT[d]-AT[c-1];
        ll B_T=BT[d]-BT[c-1];
        ll A_S=AS[b]-AS[a-1];
        ll B_S=BS[b]-BS[a-1];
        ll A=A_T-A_S;
        ll B=B_T-B_S;
        ll D=(d-c+1)-(b-a+1);
        if((2*D-A)%3==0&&(B+D)%3==0) ans[i]="YES";
        else ans[i]="NO";
    }

    REP(i,q) cout<<ans[i]<<endl;


}