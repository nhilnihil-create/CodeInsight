//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const int INF=1e+9;
const int MOD=1e+9+7;

//REPマクロ
#define REP(i,n) for(int i=0;i<(int)(n);i++)
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
    string S;
    
    cin >> N;
    cin >> S;
    
    int stack=0;
    int left=0;
    REP(i,N){
        if(S[i]=='(') stack++;
        if(S[i]==')'){
            if(stack>0) stack--;
            else left++;
        }
    }

    string res;
    REP(i,left){
        res+="(";
    }
    res+=S;
    REP(i,stack){
        res+=")";
    }
    cout<<res<<endl;
    
}