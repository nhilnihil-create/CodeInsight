#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> VECLL;
typedef vector<P> VECP;
typedef priority_queue<P,VECP,greater<P> > PQP;
typedef priority_queue<ll, VECLL, greater<ll> > PQll;

#define rep(i,a,n) for(ll i = a;i < n;i++)   
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second


int main(){
    string s;
    cin >> s;
    ll k;
    cin >> k;

    rep(i,0,s.size()){
        if(i != s.size()-1){
            if(s[i] != 'a' && (ll)('z' - s[i]) + 1 <= k){
                k -= (ll)('z' - s[i]) + 1;
                s[i] = 'a';
            }
        }
        else{
            if((ll)('z' - s[i]) + 1 <= k){
                k -= (ll)('z' - s[i]) + 1;
                k %= 26;
                s[i] = (k + 'a');
            }
            else{
                s[i] = (s[i] + k - 'a') % 26 + 'a';
            }
        }
    }
    cout << s << endl;
    return 0;
}
