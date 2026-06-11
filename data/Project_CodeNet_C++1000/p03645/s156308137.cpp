#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> x;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        if(a == 1) x.push_back(b);
        if(b == n) x.push_back(a);
    }
    int l = x.size();
    set<int> y(x.begin(),x.end());
    if(l == y.size()) cout << "IMPOSSIBLE" << endl;
    else cout << "POSSIBLE" << endl;
}