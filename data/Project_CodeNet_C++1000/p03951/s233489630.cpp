#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    int n;
    string s,t;
    cin>>n>>s>>t;
    int cnt=0,a=0;
    if(n==1){
        if(s==t) cout<<1;
        else cout<<2;
        return 0;
    }
    rep(a,n){
        int match=0;
        rep(i,n-a){
            if(s[i+a]==t[i]) match++;
        }
        if(match==n-a){
            cout<<n+a;
            return 0;
        }
    }
    cout<<2*n;
}