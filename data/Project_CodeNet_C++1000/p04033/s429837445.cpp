#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
typedef long long ll;
int main(){
    ll a, b;
    cin >> a >> b;
    string ans;
    if(a < 0 && b < 0){
        ll len = abs(a) - abs(b) + 1;
        if(len % 2 == 0)ans = "Positive";
        else ans = "Negative";
    }
    else if(a <= 0 && b >= 0)ans = "Zero";
    else ans = "Positive";
    cout << ans << endl;
    return 0;
}