#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;


int main(){

    vector<int> v(3);
    for(int i = 0; i < 3; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    bool ok = true;
    if(v[0] != 5) ok = false;
    if(v[1] != 5) ok = false;
    if(v[2] != 7) ok = false;
    
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}