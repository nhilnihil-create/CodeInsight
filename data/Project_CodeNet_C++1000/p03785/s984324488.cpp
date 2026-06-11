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
    long n,c,k;
    cin>>n>>c>>k;
    vector<long> t(n);
    rep(i,n) cin>>t[i];
    sort(all(t));
    long bus=1,num=0,time=t[0]+k;
    rep(i,n){
        if(t[i]<=time&&num<c) num++;
        else time=t[i]+k,num=1,bus++;
    }
    cout<<bus;
}