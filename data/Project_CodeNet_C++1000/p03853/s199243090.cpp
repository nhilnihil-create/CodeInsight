#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int h,w;
    cin >> h >> w;
    vector<vector<char>>c(h*2,vector<char>(w));
    for(int i=0;i<2*h;i+=2)rep(j,w) cin >> c.at(i).at(j);
    for(int i=1;i<2*h;i+=2)rep(j,w) c.at(i).at(j)=c.at(i-1).at(j);
    rep(i,2*h){
        rep(j,w) cout << c.at(i).at(j);
        cout << endl;
    }
}
    
    