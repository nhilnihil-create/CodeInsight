#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define rrep(i,n) for(int i=(n);i>=0;--i)
#define ssort(n) sort((n).begin(),(n).end())
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define INF 10101010

class Calc_Mod{//calculate mod
    public:
        unsigned int mod=1000000007;
        ll plus_mod(ll a,ll b){
            return (a+b)%mod;
        }
        ll minus_mod(ll a,ll b){
            return (a-b)%mod;
        }
        ll multi_mod(ll a,ll b){
            return a*b%mod;
        }
        ll LSM(ll a,int b){//a^b%mod
            queue<int> q;
            while(b>=1){
                q.push(b%2);
                b/=2;
            }
            ll ans=1;
            while(!q.empty()){
                if(q.front()==1){
                    ans=multi_mod(ans,a);
                }
                a=multi_mod(a,a);
                q.pop();
            }
            return ans;
        }
        ll div_mod(ll a,ll b){// a/b
            return multi_mod(a,LSM(b,mod-2));
        }
        ll combi(ll a,ll b){//aCb
            ll ans=1;
            ll kaijo=1;
            rep(i,b){
                ans=multi_mod(ans,a-i);
                kaijo=multi_mod(kaijo,b-i);
            }
            ans=div_mod(ans,kaijo);
            return ans;
        }
        ll kaijo(ll a){
            ll kaijo=1;
            rep(i,a){
                kaijo=multi_mod(kaijo,a-i);
            }
            return kaijo;
        }
};

int main()
{
    int n,m;
    cin >> n >> m;
    Calc_Mod mod;
    ll ans;
    ll comb;
    if(abs(n-m)<=1){
        if(abs(n-m)==1){
            ans=mod.multi_mod(mod.kaijo(n),mod.kaijo(m));
        }else{
            ans=mod.multi_mod(mod.kaijo(n),mod.kaijo(m));
            ans=mod.multi_mod(ans,2);
        }
    }else{
        ans=0;
    }

    cout << ans << endl;
    
}