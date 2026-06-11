#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;
const int vx[6] = {0,1,0,-1,1,-1};
const int vy[6] = {1,0,-1,0,1,1};




int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,p;
    cin >> n >> p;
    vector<int> a(n);
    int sum = 0;
    int odd = 0;
    int even = 0;
    rep(i,n){
        cin >> a[i];
        sum += a[i];
        if(a[i] % 2 == 0){
            even++;
        }else {
            odd++;
        }
    }   
    ll ans = 0;
    if(odd == 0){
        if(p == 0){
            ans = pow(2,n);
        }else{
            ans = 0;
        }
    }else{
        ans = pow(2,n-1);
    }
    cout << ans << endl;

    cout << endl;
    return 0;
}
