#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int n;
    cin >> n;
    vector<int> t(n);
    rep(i,n) cin >> t.at(i);
    int m;
    cin >> m;
    vector<int> p(m);
    vector<int> x(m);
    rep(i,m) cin >> p.at(i) >> x.at(i);
    rep(i,m){
        int ans=0;
        int a=t.at(p.at(i)-1);
        t.at(p.at(i)-1)=x.at(i);
        rep(j,n){
            ans+=t.at(j);
        }
        cout << ans << endl;
        t.at(p.at(i)-1)=a;
    }

}
