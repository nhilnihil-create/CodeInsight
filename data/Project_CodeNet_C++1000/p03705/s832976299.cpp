#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    if(a > b || (n == 1 && a != b)){
        cout << 0 << endl;
        return 0;
    }
    if(n == 1 && a == b){
        cout << 1 << endl;
        return 0;
    } 
    ll ans = b * (n-1) + a - a * (n-1) - b + 1;
    cout << ans << endl;
    return 0;
}