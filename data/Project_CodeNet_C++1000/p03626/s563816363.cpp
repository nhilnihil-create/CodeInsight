//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const ll INF=1e+9;
const ll MOD=1e+9+7;

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
    int N;
    cin >> N;
    string S1,S2;
    cin >> S1 >> S2;
    ll ans=0;

    REP(i,N){
        if(i==0){
            if(S1[i]==S2[i]){
                ans=3;
            }else{
                ans=6;
                i++;
            }
        }else{
            if(S1[i]==S2[i]){
                if(S1[i-1]==S2[i-1]){
                    ans*=2;
                    ans%=MOD;
                }
            }else{
                if(S1[i-1]==S2[i-1]){
                    ans*=2;
                }else{
                    ans*=3;
                }
                
                ans%=MOD;
                i++;
            }
        }   
    }

    cout << ans << endl;
}