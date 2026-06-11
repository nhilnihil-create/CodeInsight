#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = 2e18;
    if(a & 1){
        ans = min(ans, b * c);
    }else{
        ans = min(ans, 0LL);
    } 
    if(b & 1){
        ans = min(ans, a * c);
    }else{
        ans = min(ans, 0LL);
    } 
    if(c & 1){
        ans = min(ans, b * a);
    }else{
        ans = min(ans, 0LL);
    } 
    cout << ans << endl;
    return 0;
}
