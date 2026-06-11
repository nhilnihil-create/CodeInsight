#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const int INF = 1e9;
const int MOD = 1000000007;
const ll MX = 1e18;
        
        
int main() {
        int n;
        cin >> n;
        vector<P> vote(n);
        rep(i,n){
                cin >> vote[i].first >> vote[i].second ;
        }
        ll t = 0,a = 0;

        rep(i,n){
                if(i == 0){ t = vote[i].first; a = vote[i].second;}
                else{
                        ll k = max((t+vote[i].first-1)/vote[i].first,(a+vote[i].second-1)/vote[i].second);
                        t = k * vote[i].first;
                        a = k * vote[i].second;
                }
                //cout << t << " " << a << endl;
                
        }
        cout << t + a << endl;

}


