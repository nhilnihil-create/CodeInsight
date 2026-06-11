#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> x(m);
    vector<int> y(m);
    for(int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
    }
    vector<bool> r(n,false);
    vector<int> t(n,1);
    r[0]=true;

    for(int i = 0; i < m; i++) {
        if(r[x[i]]){
            if(t[x[i]]==1){
                r[x[i]]=false;
            }
            r[y[i]]=true;
        }
        t[x[i]]--;
        t[y[i]]++;
    }

    int cnt=0;
    for(int i = 0; i < n; i++) {
        if(r[i]) cnt++;
    }
    cout << cnt << "\n";

    return 0;
}