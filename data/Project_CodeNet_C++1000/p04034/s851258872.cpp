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
    vector<int> box(n);
    vector<bool> red(n);
    red[0]=true;
    rep(i,n) box[i]=1;
    int x,y;
    rep(i,m){
        cin>>x>>y;
        box[x-1]--,box[y-1]++;
        if(red[x-1]) red[y-1]=true;
        if(box[x-1]==0) red[x-1]=false;
    }
    int cnt=0;
    rep(i,n) if(red[i]) cnt++;
    cout<<cnt;
}