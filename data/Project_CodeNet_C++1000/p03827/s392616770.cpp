#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;
#define reverse(s) reverse(s.begin(),s.end())


ll gcd(ll a, ll b) {
    if (b==0) return a;
    else return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main(){
    int n;
    string s;
    cin >> n >> s;

    int x(0),ans(0);
    rep(i,n){
        if(s[i]=='I'){
            x += 1;
            ans = max(ans,x);
        }
        if(s[i]=='D'){
            x -= 1;
        }
    }

    cout << ans << endl;

    return 0;
}