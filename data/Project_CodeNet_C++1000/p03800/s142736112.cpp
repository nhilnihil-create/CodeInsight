#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
#define MOD2 998244353
#define pb emplace_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define sz(x) (ll)x.size()
#define F first
#define S second
#define FOR(i,a,b) for(ll i=a;i<=b;++i)
#define ROF(i,a,b) for(ll i=a;i>=b;--i)
#define trace(x) cerr<<#x<<": "<<x<<'\n';
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
#define T int
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>
auto clk=clock();
 
ll mexp(ll a, ll b, ll m){
    ll ans=1;
    a%=m;
    while(b){
        if(b&1) ans=ans*a%m;
        b>>=1;
        a=a*a%m;
    }
    return ans;
}

string s;
string st[4] = {"SS", "SW", "WS", "WW"};

int main(){
    IOS
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int n;
    cin >> n;
    cin >> s;
    FOR(i,0,3){
        string ans = st[i];
        FOR(j,1,n-2){
            if(s[j] == 'o'){
                if(ans[j] == 'S'){
                    ans += ans[j-1];
                }
                else{
                    if(ans[j-1] == 'W'){
                        ans += "S";
                    }
                    else{
                        ans += "W";
                    }
                }
            }
            else{
                if(ans[j] == 'S'){
                    if(ans[j-1] == 'W'){
                        ans += "S";
                    }
                    else{
                        ans += "W";
                    }
                }
                else{
                    ans += ans[j-1];
                }
            }
        }
        //cout << ans << endl;
        bool yes = 1;
        if(s[n-1] == 'o'){
            if(ans[n-1] == 'S'){
                if(ans[n-2] != ans[0]){
                    yes = 0;
                }
            }
            else{
                if(ans[n-2] == ans[0]){
                    yes = 0;
                }
            }
        }
        else{
            if(ans[n-1] == 'S'){
                if(ans[n-2] == ans[0]){
                    yes = 0;
                }
            }
            else{
                if(ans[n-2] != ans[0]){
                    yes = 0;
                }
            }
        }
        if(s[0] == 'o'){
            if(ans[0] == 'S'){
                if(ans[n-1] != ans[1]){
                    yes = 0;
                }
            }
            else{
                if(ans[n-1] == ans[1]){
                    yes = 0;
                }
            }
        }
        else{
            if(ans[0] == 'S'){
                if(ans[n-1] == ans[1]){
                    yes = 0;
                }
            }
            else{
                if(ans[n-1] != ans[1]){
                    yes = 0;
                }
            }
        }
        if(yes){
            cout << ans;
            return 0;
        }
    }
    cout << -1;


    cerr<<endl<<endl<<"Time: "<<fixed<<setprecision(12)<<(long double)(clock()-clk)/CLOCKS_PER_SEC<<" ms"<<endl<<endl;
 
    return 0;
}