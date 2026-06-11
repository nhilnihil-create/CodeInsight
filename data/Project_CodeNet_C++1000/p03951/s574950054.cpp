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
    rep(i,n){
        int cnt=0;
        rep(j,n-i) if(s[j+i]==t[j]) cnt++;
        if(cnt==n-i){
            cout<<2*n-cnt;
            return 0;
        }
    }
    cout<<2*n;
}