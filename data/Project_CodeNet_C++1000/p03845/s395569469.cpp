#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> t(n); 
    
    int sum=0;
    rep(i, n){
        cin >> t[i];
        sum += t[i];
    }
    int m; cin >> m;
    vector<int> p(m), x(m);
    rep(i, m) cin >> p[i] >> x[i];

    vector<int> res(m);
    for(int i=0; i<m; i++){
        res[i] = sum - t[p[i]-1] + x[i];
        cout << res[i] << endl;
    }
    return 0;
}