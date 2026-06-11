#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n,1);
    vector<bool> b(n,false);
    b[0] = true;
    for(int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        x--;y--;
        a[x]--; a[y]++;
        if(b[x]){
            b[y] = true;
            if(a[x] == 0) b[x] = false;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(b[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}