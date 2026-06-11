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
    int N;
    cin>>N;
    priority_queue<int> A;
    int a;
    REP(i,N){
        cin >> a;
        A.push(a);
    }
    int cur,before;
    cur=A.top();
    A.pop();
    int sum=0;
    int m=0;
    int num=INF;
    while(!A.empty()){
        before=cur;
        cur=A.top();
        A.pop();
        if(cur==before){
            if(cur==num){
                sum++;
            }else{
                sum+=2;
                num=cur;
                m++;
            }
        }else{
            num=cur;
        }
    }
    cout << N -(sum-m)- (sum-m)%2 << endl;
    
}