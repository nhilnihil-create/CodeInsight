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
    string s;
    int n;
    cin>>n>>s;
    int x=0,y=0;
    rep(i,n){
        if(s[i]=='I') y++;
        else y--;
        x=max(x,y);
    }
    cout<<x;
}