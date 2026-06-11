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
    ll N,M;
    cin>>N>>M;
    vl X(N);
    REP(i,N) cin>>X[i];
    map<ll,ll> mp1;
    map<ll,pair<ll,ll>> mp2;
    
    //初期化
    REP(i,N){
        mp1[X[i]]++;
    }
    
    for(auto itr=mp1.begin();itr!=mp1.end();itr++){
        ll x=itr->first;
        ll val=itr->second;
        ll key=x%M;
   		
        // val_p:ペアの数 val_amari:あまり
        ll val_p=val/2;
        ll val_amari=val-val_p*2;
        mp2[key].first+=val_p;
        mp2[key].second+=val_amari;
    }

    ll ans=0;
    ll tmp=0;
	ll cnt=0;
    for(auto itr=mp2.begin();itr!=mp2.end();itr++){
      	
        ll x1=itr->first;
        ll p1=itr->second.first;
        ll amari1=itr->second.second;
        ll num1=2*p1+amari1;

        ll x2=(M-x1)%M;

        if(!mp2.count(x2)){
            tmp+=p1;
        }else{
            ll p2=mp2[x2].first;
            ll amari2=mp2[x2].second;
            ll num2=2*p2+amari2;
            if(x1==x2){
                tmp+=(num1/2);
            }else{
                if(num1<num2){
                    swap(p1,p2);
                    swap(amari1,amari2);
                    swap(num1,num2);
                }

                //少ない方の全部を使ってペアを作る
                ans+=num2;
                amari1-=num2;

                //多い方の残りでできるだけペアを作る
                if(amari1<0){
                    p1-=((abs(amari1)+1)/2);
                }
                
                ans+=p1;
            }
        }
    }
    ans/=2;
    ans+=tmp;
    cout<<ans<<endl;
    
}