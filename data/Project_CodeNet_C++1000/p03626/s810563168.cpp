#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1000000007;

int main(){
    int n;
    string s,t;
    cin>>n>>s>>t;
    /*調べる一つ前のドミノの状態
    0は何もない,1は縦,2は横*/
    int now=0;
    long long ans=0;
    rep(i,n){
        if(now==0){//はじめ
            if(s[i]==t[i]){//縦の時
                ans=3;
                now=1;
            }
            else{//横の時
                ans=6;
                i++;//次のドミノにとばす
                now=2;
            }
        }
        else if(now==1){//前が縦の時
            if(s[i]==t[i]){//縦の時
                ans=(ans*2)%MOD;
                now=1;
            }
            else{//横の時
                ans=(ans*2)%MOD;
                i++;//次のドミノにとばす
                now=2;
            }
        }
        else{//前が横の時
            if(s[i]==t[i]){//縦の時
                ans=(ans*1)%MOD;
                now=1;
            }
            else{//横の時
                ans=(ans*3)%MOD;
                i++;//次のドミノにとばす
                now=2;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
