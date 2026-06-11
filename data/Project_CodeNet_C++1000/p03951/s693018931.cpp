#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};

vector<pair<ll,ll>> f(ll n){
    vector<pair<ll,ll>> p;
    for(ll i = 2;i * i<=n;++i){
        if(n%i == 0){
            ll tmp = 0;
            while(n%i == 0){
                n/=i;
                tmp++;
            }
            p.push_back(make_pair(i,tmp));
        }
    }
    if(n != 1) p.push_back(make_pair(n,1));
    return p;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s,t;
    cin >> n >> s >>t;
    int same = 0;

    rep(i,n){
        rep(j,n){
            if(s[i] == t[same]){
                same++;
                break;
            }
            else same = 0;
        }
    }
    cout << 2*n-same << endl;

    return 0;
}
