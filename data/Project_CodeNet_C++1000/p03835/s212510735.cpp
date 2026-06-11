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
    int k,s;
    cin>>k>>s;
    ll cnt=0;
    rep(x,k+1){
        rep(y,k+1){
            if(s-x-y>=0&&s-x-y<=k) cnt++;
        }
    }
    cout<<cnt;
}