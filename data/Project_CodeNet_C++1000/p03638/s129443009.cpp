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
    int H,W;
    cin >> H >>W;
    int N;
    cin >> N;
    vector<int> a(N);
    REP(i,N) cin>>a[i];
    vector<vector<int>> G(H+2,vector<int>(W+2,-1));

    vector<pair<int,int>> mode={{0,1},{1,0},{0,-1},{-1,0}};
    REP(i,H+2){
        REP(j,W+2){
            if(i==0||i==H+1||j==0||j==W+1) G[i][j]=0;
        }
    }
    int cnt=0;
    int num=0;
    int cnt2=0;
    int i_mode=0;
    int x,y;
    x=1;
    y=1;
    while(cnt<H*W){
        G[x][y]=num+1;
        cnt2++;
        if(cnt2==a[num]){
            cnt2=0;
            num++;
        }
        if(G[x+mode[i_mode].first][y+mode[i_mode].second]!=-1){
            i_mode++;
            i_mode%=4;
        }
        x=x+mode[i_mode].first;
        y=y+mode[i_mode].second;
        cnt++;
        
    }

    REP2(i,1,H+1){
        REP2(j,1,W+1){
            cout << G[i][j];
            if(j!=W) cout << " ";
        }
        cout << endl;
    }
    

    
}