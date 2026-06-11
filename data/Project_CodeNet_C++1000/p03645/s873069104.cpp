#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;

int main(){
    int n,m; cin >> n >>m;
    int x,y;
    vector<vector<int>> cnct(n+1,vector<int>(0));
    rep(i,m){
        cin >> x >> y;
        cnct[x].push_back(y);
        cnct[y].push_back(x);
    }
    for(auto p: cnct[1]){
        for(auto q: cnct[p]){
            if(q==n){
                cout << "POSSIBLE" << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;


}