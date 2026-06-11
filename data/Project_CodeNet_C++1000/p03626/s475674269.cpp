#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include <bitset>
#include <numeric>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[8]={ 0, 1, 0,-1, 1, 1,-1,-1}; // x軸方向への変位
ll dy[8]={ 1, 0,-1, 0, 1,-1, 1,-1}; // y軸方向への変位

int main(void){
    ll n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    ll ans = 1;
    ll INF = 1e+9+7;
    for(ll i = 0; i < n; i++){
        if(i==0 && s[i]==t[i]) ans*=3;
        else if(i==0 && s[i]!=t[i]) {
            ans*=6; i++;
        }
        else if(s[i]==t[i] && s[i-1]==t[i-1])
            ans *= 2;
        else if(s[i]!=t[i] && s[i-1]!=t[i-1]){
            ans*=3; i++;
        }
        else if(s[i]!=t[i] && s[i-1]==t[i-1]){
            ans*=2; i++;
        }
        ans%=INF;
        //cout << i << " " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
