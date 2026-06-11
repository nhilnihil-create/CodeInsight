#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,k;
    cin >> n >> m >> k;
    string ans="No";
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if((i*(m-j)+(n-i)*j)==k){
                ans="Yes";
                break;
            }
        }
        if(ans=="Yes") break;
    }
    cout << ans << endl;
}