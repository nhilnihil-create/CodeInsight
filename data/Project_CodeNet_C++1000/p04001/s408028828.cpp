#include <bits/stdc++.h>
#include <string>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//定数
#define INF 1000000000 //10^9:極めて大きい値,∞
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second　//pairの二つ目の要素

int main(){
    string s;
    cin>>s;
    int n=s.size();
    ll ans=0;
    rep(i,1<<(n-1)){
        int k=0;
        ll v=0;
        int ii=i;
        rep(j,n){
            v=v*10+(s[j]-'0');
            if(ii%2==1){
                ans+=v;
                v=0;
            }
            ii/=2;
        }
        ans+=v;
    }
    cout<<ans<<endl;
    return 0;
}