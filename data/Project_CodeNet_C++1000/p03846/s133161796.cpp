#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    ll n;
    cin >> n;
    vector<int> v(n);
    rep(i,n) cin >> v[i];
    map<int,int> mii;
    rep(i,n){
        mii[v[i]]++;
    }
    if(n%2 == 0){
        if(mii.size()!=n/2){
            //cout<<"Yes1"<<endl;
            cout<< 0 <<endl;
            return 0;
        }else{
            for(auto u : mii){
                if(u.first%2!=0 && u.second==2);
                else{
                    //cout<<u.first<<" "<<u.second<<endl;
                    //cout<<"yes2"<<endl;
                    cout << 0 << endl;
                    return 0;
                }
            }
            int ans = 2;
            rep(i,n/2-1){
                ans *= 2;
                ans %= mod;
            }
            cout << ans << endl;
        }
    }
    else{
        if(mii.size()!=n/2+1){
            cout<< 0 <<endl;
            return 0;
        }else{
            bool ok = 0;
            for(auto u : mii){
                if(u.first==0 && u.second == 1){
                    ok = 1;
                    continue;
                }
                if(u.first%2==0 && u.second==2);
                else{
                    cout << 0 << endl;
                    return 0;
                }
            }
            if(ok){
                int ans = 2;
                rep(i,n/2-1){
                    ans *= 2;
                    ans %= mod;
                }
                if(n!=1)cout << ans << endl;
                else cout<<1<<endl;
            }
            else cout << 0 << endl;
        }
    }
    return 0;
}