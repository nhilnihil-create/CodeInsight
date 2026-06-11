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
    ll H,W;
    cin>>H>>W;
    ll h1,h2,w1,w2,S1,S2,S3,S_MAX,S_MIN;
    ll S=H*W;
    ll ans=INF;
    //縦→縦
    w1=W/3;
    w2=w1+(W-w1)/2;
    S1=H*w1;
    S2=H*(w2-w1);
    S3=H*(W-w2);
    S_MAX=max(S1,S2);
    S_MAX=max(S_MAX,S3);
    S_MIN=min(S1,S2);
    S_MIN=min(S_MIN,S3);
    if(w1!=0&&w1!=w2&&w2!=W){
        ans=min(S_MAX-S_MIN,ans);
    }
    

    //縦→横A
    w1=W/3;
    S1=H*w1;
    h2=H/2;
    S2=h2*(W-w1);
    S3=S-S1-S2;
    S_MAX=max(S1,S2);
    S_MAX=max(S_MAX,S3);
    S_MIN=min(S1,S2);
    S_MIN=min(S_MIN,S3);
    if(w1!=0&&h2!=0&&h2!=H){
        ans=min(S_MAX-S_MIN,ans);
    }



    //縦→横B
    w1=W/3+1;
    S1=H*w1;
    h2=H/2;
    S2=h2*(W-w1);
    S3=S-S1-S2;
    S_MAX=max(S1,S2);
    S_MAX=max(S_MAX,S3);
    S_MIN=min(S1,S2);
    S_MIN=min(S_MIN,S3);
    if(w1!=W&&h2!=0&&h2!=H){
        ans=min(S_MAX-S_MIN,ans);
    }

    swap(H,W);
    //縦→縦
    w1=W/3;
    w2=w1+(W-w1)/2;
    S1=H*w1;
    S2=H*(w2-w1);
    S3=H*(W-w2);
    S_MAX=max(S1,S2);
    S_MAX=max(S_MAX,S3);
    S_MIN=min(S1,S2);
    S_MIN=min(S_MIN,S3);
    if(w1!=0&&w1!=w2&&w2!=W){
        ans=min(S_MAX-S_MIN,ans);
    }
    
    //縦→横A
    w1=W/3;
    S1=H*w1;
    h2=H/2;
    S2=h2*(W-w1);
    S3=S-S1-S2;
    S_MAX=max(S1,S2);
    S_MAX=max(S_MAX,S3);
    S_MIN=min(S1,S2);
    S_MIN=min(S_MIN,S3);
    if(w1!=0&&h2!=0&&h2!=H){
        ans=min(S_MAX-S_MIN,ans);
    }

    //縦→横B
    w1=W/3+1;
    S1=H*w1;
    h2=H/2;
    S2=h2*(W-w1);
    S3=S-S1-S2;
    S_MAX=max(S1,S2);
    S_MAX=max(S_MAX,S3);
    S_MIN=min(S1,S2);
    S_MIN=min(S_MIN,S3);
    if(w1!=W&&h2!=0&&h2!=H){
        ans=min(S_MAX-S_MIN,ans);
    }
    cout<<ans<<endl;
    

}