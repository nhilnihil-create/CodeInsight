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
    int city[n]={0};
    rep(i,m){
        int a,b;
        cin>>a>>b;
        city[a-1]++;
        city[b-1]++;
    }
    rep(i,n) cout<<city[i]<<endl;
}