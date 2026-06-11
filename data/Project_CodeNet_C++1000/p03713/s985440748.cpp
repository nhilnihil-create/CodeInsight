#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
using namespace std;
typedef long long int ll;
ll h, w;
 
ll solve(ll x, ll y){
    ll ans = h * w;
    for(int i = 1; i < x; i++){
        ll s1 = i * y;
        ll s2 = (x - i) / 2 * y;
        ll s3 = x * y - s1 - s2;
        ll smax = max(s1, max(s2, s3));
        ll smin = min(s1, min(s2, s3));
        ans = min(ans, smax - smin);
 
        s2 = (x - i) * (y / 2);
        s3 = x * y - s1 - s2;
        smax = max(s1, max(s2, s3));
        smin = min(s1, min(s2, s3));
        ans = min(ans, smax - smin);
    }
    return ans;
}
 
int main(){
    cin >> h >> w;
    cout << min(solve(h, w), solve(w, h)) << endl;
    return 0 ;
}