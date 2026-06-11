#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cmath>
using namespace std;
#define MOD 1000000007
#define INF 1<<30
#define LINF (ll)1<<62
#define MAX 5100
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> P;
typedef vector<pair<ll, ll>> vpl;

int main(){
    ll n; cin >> n;
    string s1,s2;
    cin >> s1 >> s2;
    ll ans = 3;
    bool yoko = false;
    rep(i,n){
        if(s1[i] == s2[i]){
            if(i==0) continue;
            if(!yoko){
                ans *= 2;
                ans %= MOD;
            }
            yoko = false;
        }else{
            if(yoko){
                ans *= 3;
                ans %= MOD;
            }else{
                ans *= 2;
                ans %= MOD;
            }
            yoko = true;
            i++;
        }
    }
    cout << ans << endl;
}