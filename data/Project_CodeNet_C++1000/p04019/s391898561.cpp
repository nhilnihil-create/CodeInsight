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
    string q;
    cin>>q;
    int p=q.size();
    bool n=false,e=false,w=false,s=false;
    rep(i,p){
        if(q[i]=='N') n=true;
        else if(q[i]=='E') e=true;
        else if(q[i]=='W') w=true;
        else if(q[i]=='S') s=true;
    }
    if(n&&!s) cout<<"No";
    else if(e&&!w) cout<<"No";
    else if(w&&!e) cout<<"No";
    else if(s&&!n) cout<<"No";
    else cout<<"Yes";
}