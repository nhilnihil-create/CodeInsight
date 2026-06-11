#include<cstdio>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<iomanip>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
#define DEBUG(x) cout<<#x<<"="<<x<<endl
#define DEBUG2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
typedef long long ll;
class Solver{
public:
    static const int MAXN=60;
    static const ll MOD=1e9+7;
    int N;
    char s1[MAXN];
    char s2[MAXN];
    vector<int>pat;
    void solve(){
        cin>>N>>s1>>s2;
        for(size_t u=0;u<N;u++){
            if(u!=N-1){
                if(s1[u]==s1[u+1]){
                    pat.push_back(0);
                    u++;
                }
                else pat.push_back(1);
            }
            else pat.push_back(1);
        }
        // for(auto p:pat)cout<<p<<" ";
        ll ans=1;
        int pre=-1;
        for(size_t u=0;u<pat.size();u++){
            if(u==0){
                if(pat[u]==1)ans=(ans*3)%MOD;
                else ans=(ans*6)%MOD;
            }
            else{
                if(pat[u]==1){
                    if(pre==1)ans=(ans*2)%MOD;
                }
                else {
                    if(pre==1)ans=(ans*2)%MOD;
                    else ans=(ans*3)%MOD;
                }
            }
            pre=pat[u];
        }
        cout<<ans;
    }
};
int main()
{
    // freopen("in.txt","r",stdin);
    (new Solver())->solve();
}