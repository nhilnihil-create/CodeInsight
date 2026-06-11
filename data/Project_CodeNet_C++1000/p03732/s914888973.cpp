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

//vectorの扱い
#define ALL(x) (x).begin(),(x).end() //sortなどの引数省略
#define SIZE(x) ((ll)(x).size()) //size
#define MAX(x) *max_element(ALL(x)) //最大値
#define MIN(x) *min_element(ALL(x)) //最小値

//グローバル変数


//ライブラリ挿入


int main(){
    int N,W;
    cin >> N >> W;
    vector<vector<ll>> V(4);
    int w1,w,v;
    cin >> w >> v;
    w1=w;
    V[0].push_back(v);
    REP2(i,1,N){
        cin >>w>>v;
        V[w-w1].push_back(v);
    }

    REP(i,4){
        sort(V[i].begin(),V[i].end(),greater<ll>());
    }

    vector<vector<ll>> Vsum(4,vector<ll>(110,0));
    REP(i,4){
        REP(j,V[i].size()){
            Vsum[i][j+1]=Vsum[i][j]+V[i][j];
        }
    }
    

    ll ans=0;
    REP(i,V[0].size()+1){
        REP(j,V[1].size()+1){
            REP(k,V[2].size()+1){
                REP(l,V[3].size()+1){
                    if(w1*i+(w1+1)*j+(w1+2)*k+(w1+3)*l<=W){
                        ans=max(ans,Vsum[0][i]+Vsum[1][j]+Vsum[2][k]+Vsum[3][l]);
                    }
                }
            }
        }
    }
    cout << ans <<endl;

    
}