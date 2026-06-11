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
    int A,B,C,D,E,F;
    cin>>A>>B>>C>>D>>E>>F;
    set<int> sugar,water;
    

    REP(i,31){
        REP(j,31){
            if(100*A*i+100*B*j>F) continue;
            water.insert(100*A*i+100*B*j);
        }
    }

    REP(i,3001){
        REP(j,3001){
            if(C*i+D*j>=F) continue;
            sugar.insert(C*i+D*j);
        }
    }


    int ans_w=100*A;
    int ans_s=0;
    
    for(auto itr=water.begin();itr!=water.end();itr++){
        int w=(*itr);
        auto itr2=sugar.upper_bound(F-w);
        itr2--;
        int s=(*itr2);
        while((w*E)<(100*s)){
            itr2--;
            s=(*itr2);
        }
        if(w!=0&&(s+w)<=F){
            int cur=s*(ans_w+ans_s);
            int bef=ans_s*(w+s);
            
            if(cur>bef){
                ans_w=w;
                ans_s=s;
            }
        }
        
    }

    // for(auto itr=sugar.begin();itr!=sugar.end();itr++){
    //     int s=*itr;
    //     auto itr2=water.upper_bound(F-s);
    //     itr2--;
    //     int w=*itr2;
    //     if(w!=0&&(w*E)>=(100*s)&&(s+w)<=F){
    //         int cur=s*(ans_w+ans_s);
    //         int bef=ans_s*(w+s);
            
    //         if(cur>bef){
    //             ans_w=w;
    //             ans_s=s;
    //         }
    //     }
        
    // }
    cout<<(ans_w+ans_s)<<" "<<ans_s<<endl;


}