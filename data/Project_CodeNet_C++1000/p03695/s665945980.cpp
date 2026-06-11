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
    int n; cin>>n;
    vector<int> color(9);
    int a;
    rep(i,n){
        cin>>a;
        if(a<3200) color[a/400]++;
        else color[8]++;
    }
    int cnt=0;
    rep(i,8) if(color[i]!=0) cnt++;
    cout<<max(1,cnt)<<" "<<cnt+color[8];
}