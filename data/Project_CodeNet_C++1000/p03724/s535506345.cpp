#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> d(n);
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        d[a]++;
        d[b]++;
    }   
    bool flag = true; 
    for(int i = 0; i < n; i++){
        if(d[i]%2 == 1) flag = false;
    }
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}