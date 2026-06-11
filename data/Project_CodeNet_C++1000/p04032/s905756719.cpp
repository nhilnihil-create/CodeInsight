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
    string s;
    cin>>s;
    int N=s.size();
    REP2(i,1,N){
        if(s[i]==s[i-1]){
            cout << i <<" "<<i+1<<endl;
            return 0;
        }else if(i!=1&&s[i-2]==s[i]){
            cout << i-1 << " " << i+1<<endl;
            return 0;
        }
    }
    cout << -1 << " " << -1 <<endl;   
}