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
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> s(m);
    vector<int> a(n);
    rep(i,m){
        cin>>s[i].first>>s[i].second;
        if(s[i].first==1) a[s[i].second-1]++;
        if(s[i].second==n) a[s[i].first-1]++;
    }
    rep(i,n){
        if(a[i]==2){
            cout<<"POSSIBLE";
            return 0;
        }
    }
    cout<<"IMPOSSIBLE";
}