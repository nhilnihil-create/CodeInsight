#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
typedef long long ll;
typedef pair<int, int> pii;
int main(){
    ll h,w; int n; cin >> h >> w >> n;
    vector<int> a(n), b(n);
    rep(i,n) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    map<pii, int> mp;
    vector<ll> num(10);
    rep(i,n){
        rep(j,3){
            rep(k,3){
                if(0 <= a[i]-j && a[i]-j < h-2 && 0 <= b[i]-k && b[i]-k < w-2) mp[make_pair(a[i]-j, b[i]-k)]++;
            }
        }
    }
    for(auto P : mp) num[P.second]++;
    ll sum = accumulate(ALL(num), 0LL);
    num[0] = (h-2LL)*(w-2LL) - sum;
    rep(i,10) cout << num[i] << endl;
}